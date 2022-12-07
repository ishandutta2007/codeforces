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
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

char s[200005];
struct SEG{
	int tree[524288]={0};
	char C;

	void init(int node, int S, int E)
	{
		if (S == E)
		{
			tree[node] = s[S]==C;
			return;
		}
		init(2 * node, S, (S + E) / 2);
		init(2 * node + 1, (S + E) / 2 + 1, E);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}

	void upd(int node, int S, int E, int k)
	{
		if (S == E){
			tree[node] = s[S]==C;
			return;
		}
		if (k <= (S + E) / 2)upd(node * 2, S, (S + E) / 2, k);
		else upd(node * 2 + 1, (S + E) / 2 + 1, E, k);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
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
}R,P,S;
int n,q;
int res(){
	if(R.tree[1]==n || P.tree[1]==n || S.tree[1]==n)return 0;
	if(R.tree[1]==0)return P.tree[1];
	if(P.tree[1]==0)return S.tree[1];
	if(S.tree[1]==0)return R.tree[1];
	int PL=P.findK(1,1,n,1),PR=P.findK(1,1,n,P.tree[1]);
	int RL=R.findK(1,1,n,1),RR=R.findK(1,1,n,R.tree[1]);
	int SL=S.findK(1,1,n,1),SR=S.findK(1,1,n,S.tree[1]);
	int res=0;
	res+=R.find(1,1,n,PL,SL-1)+R.find(1,1,n,SR+1,PR);
	res+=S.find(1,1,n,RL,PL-1)+S.find(1,1,n,PR+1,RR);
	res+=P.find(1,1,n,SL,RL-1)+P.find(1,1,n,RR+1,SR);
	return res;
}
int main() {
	R.C='R',P.C='P',S.C='S';
	scanf("%d%d",&n,&q);
	scanf("%s",s+1);
	R.init(1,1,n);P.init(1,1,n);S.init(1,1,n);
	printf("%d\n",n-res());
	while(q--){
		int i;
		char c;
		scanf("%d %c",&i,&c);
		s[i]=c;
		R.upd(1,1,n,i);P.upd(1,1,n,i);S.upd(1,1,n,i);
		printf("%d\n",n-res());
	}
}