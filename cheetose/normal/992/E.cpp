#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define y0 y12
#define y1 y22
#define INF 987654321
#define PI 3.141592653589793238462643383279502884
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset((a),0,sizeof(a))
#define MEM_1(a) memset((a),-1,sizeof(a))
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
typedef vector<db> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const int MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

ll a[200002];
ll mxtree[524288],sumtree[524288];
int n,q;
void init(int node, int S, int E)
{
	if (S == E)
	{
		mxtree[node] = sumtree[node] = a[S];
		return;
	}
	init(2 * node, S, (S + E) / 2);
	init(2 * node + 1, (S + E) / 2 + 1, E);
	sumtree[node] = sumtree[node * 2] + sumtree[node * 2 + 1];
	mxtree[node]=max(mxtree[node*2],mxtree[node*2+1]);
}
void upd(int node, int S, int E, int k)
{
	if (S == E)
	{
		mxtree[node] = sumtree[node] = a[k];
		return;
	}
	if(k<=(S+E)/2)upd(2 * node, S, (S + E) / 2,k);
	else upd(2 * node + 1, (S + E) / 2 + 1, E,k);
	sumtree[node] = sumtree[node * 2] + sumtree[node * 2 + 1];
	mxtree[node]=max(mxtree[node*2],mxtree[node*2+1]);
}
int go(int node,int S,int E,ll sum){
	if(S==E)return S;
	int L=node*2,R=L+1,M=(S+E)>>1;
	if(mxtree[L]>=sum)return go(L,S,M,sum);
	else return go(R,M+1,E,sum);
}
int find(int node,int S,int E,int i,int j,ll sum){
	if (i > E || j < S)return n;
	if (i <= S && j >= E){
		if(mxtree[node]<sum)return n;
		return go(node,S,E,sum);
	}
	int t=find(node*2,S,(S+E)>>1,i,j,sum);
	if(t!=n)return t;
	return find(node*2+1,(S+E)/2+1,E,i,j,sum);
}
ll sumfind(int node, int S, int E, int i, int j)
{
	if (i > E || j < S)return 0;
	if (i <= S && j >= E)return sumtree[node];
	return sumfind(node * 2, S, (S + E) / 2, i, j) + sumfind(node * 2 + 1, (S + E) / 2 + 1, E, i, j);
}
int main(){
	scanf("%d%d",&n,&q);
	fup(i,0,n-1,1)scanf("%lld",a+i);
	init(1,0,n-1);
	while(q--){
		int i,x;
		scanf("%d%d",&i,&x);
		a[--i]=x;
		upd(1,0,n-1,i);
		if(a[0]==0){
			puts("1");
			continue;
		}
		int now=0;
		ll sum=a[0];
		while(now<n){
			now=find(1,0,n-1,now+1,n-1,sum);
			if(now==n){
				puts("-1");
				break;
			}
			sum=sumfind(1,0,n-1,0,now-1);
			if(sum==a[now]){
				printf("%d\n",now+1);
				break;
			}
			sum+=a[now];
		}
	}
}