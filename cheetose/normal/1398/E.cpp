#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define y0 y12
#define y1 y22
#define INF 987654321987654321
#define PI 3.141592653589793238462643383279502884
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset((a),0,sizeof(a));
#define MEM_1(a) memset((a),-1,sizeof(a));
#define ALL(a) a.begin(),a.end()
#define SYNC ios_base::sync_with_stdio(false);cin.tie(0)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> Pi;
typedef pair<ll, ll> Pll;
typedef pair<ld, ld> Pd;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<double> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef tuple<int, int, int> iii;
typedef tuple<int,int,int,int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM=MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[]={2,2,-2,-2,1,1,-1,-1},ddy[]={1,-1,1,-1,2,-2,2,-2};

int tot,T;
ll TOT;
Pi query[200002];
struct Tree{
	int tree[524288]={0};
	void upd(int node, int S, int E, int k, int dif)
	{
		tree[node] += dif;
		if (S == E)return;
		if (k <= (S + E) / 2)upd(node * 2, S, (S + E) / 2, k, dif);
		else upd(node * 2 + 1, (S + E) / 2 + 1, E, k, dif);
	}
	int find(int node, int S, int E, int i, int j)
	{
		if (i > E || j < S)return 0;
		if (i <= S && j >= E)return tree[node];
		return find(node * 2, S, (S + E) / 2, i, j) + find(node * 2 + 1, (S + E) / 2 + 1, E, i, j);
	}
	int findK(int node, int S, int E, int k)
	{
		if (S == E)return S;
		if (k <= tree[node * 2])return findK(node * 2, S, (S + E) / 2, k);
		return findK(node * 2 + 1, (S + E) / 2 + 1, E, k - tree[node * 2]);
	}
}A,B;
Vi vv={0};
ll tree2[200005];
int N;
void upd2(int i, ll k)
{
	while (i <= N)
	{
		tree2[i] += k;
		i += (i&-i);
	}
}
ll sum(int i)
{
	ll c = 0;
	while (i > 0)
	{
		c += tree2[i];
		i -= (i&-i);
	}
	return c;
}
int main(){
	int q;
	scanf("%d",&q);
	fup(i,0,q-1,1){
		scanf("%d%d",&query[i].X,&query[i].Y);
		if(query[i].Y>0)vv.pb(query[i].Y);
	}
	sort(ALL(vv));
	vv.resize(unique(ALL(vv))-vv.begin());
	fup(i,0,q-1,1){
		int y=query[i].Y;
		bool ok=y>0;
		y=abs(y);
		y=lower_bound(ALL(vv),y)-vv.begin();
		query[i].Y=y*(ok?1:-1);
	}
	N=vv.size();
	fup(i,0,q-1,1){
		auto [o,x]=query[i];
		if(x>0){
			TOT+=2*vv[x];
			tot++;
			A.upd(1,0,N-1,x,1);
			upd2(x,vv[x]);
		}
		else{
			TOT-=2*vv[-x];
			tot--;
			A.upd(1,0,N-1,-x,-1);
			upd2(-x,-vv[-x]);
		}
		if(o==1){
			if(x>0){
				T++;
				B.upd(1,0,N-1,x,1);
			}
			else {
				T--;
				B.upd(1,0,N-1,-x,-1);
			}
		}
		if(tot==0)puts("0");
		else if(T==0){
			printf("%lld\n",sum(N));
		}else{
			ll res=TOT;
			int x=B.findK(1,0,N-1,1);
			res-=vv[x];
			A.upd(1,0,N-1,x,-1);
			upd2(x,-vv[x]);
			int y=A.findK(1,0,N-1,tot-T-1);
			int s=A.find(1,0,N-1,0,y-1);
			res-=sum(y-1)+1LL*vv[y]*(tot-T-1-s);
			printf("%lld\n",res);
			A.upd(1,0,N-1,x,1);
			upd2(x,vv[x]);
		}
	}
}