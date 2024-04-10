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
#define COMPRESS(a) sort(ALL(a));a.resize(unique(ALL(a))-a.begin())
#define SYNC ios_base::sync_with_stdio(false);cin.tie(0)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> Pi;
typedef pair<ll, ll> Pll;
typedef pair<db, db> Pd;
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

struct Node {
	int sum,mx,mn;
};
Node tree[524288];
Node merge(const Node &N1,const Node &N2){
	Node T;
	T.sum=N1.sum+N2.sum;
	T.mx=max(N1.mx,N1.sum+N2.mx);
	T.mn=min(N1.mn,N1.sum+N2.mn);
	return T;
}
char s[200002];
void init(int node,int S,int E){
	if(S==E){
		int tt;
		if(s[S]=='+')tt=1;
		else tt=-1;
		tree[node]={tt,tt,tt};
		return;
	}
	init(node*2,S,(S+E)/2);
	init(node*2+1,(S+E)/2+1,E);
	tree[node]=merge(tree[node*2],tree[node*2+1]);
}
Node find(int node, int S, int E, int i, int j)
{
	Node T = { -INF,-INF,-INF };
	if (i > E || j < S)return T;
	if (i <= S && j >= E)return tree[node];
	Node L = find(node * 2, S, (S + E) / 2, i, j);
	Node R = find(node * 2 + 1, (S + E) / 2 + 1, E, i, j);
	if (L.sum == T.sum)return R;
	if (R.sum == T.sum)return L;
	return merge(L,R);
}
void solve(){
	int n,m;
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	init(1,1,n);
	while(m--){
		int mx=0,mn=0;
		int l,r;
		scanf("%d%d",&l,&r);
		Node L=find(1,1,n,1,l-1);
		Node R=find(1,1,n,r+1,n);
		if(L.sum!=-INF){
			mx=max(mx,L.mx);
			mn=min(mn,L.mn);
			if(R.sum!=-INF){
				mx=max(mx,L.sum+R.mx);
				mn=min(mn,L.sum+R.mn);
			}
		}else if(R.sum!=-INF){
			mx=max(mx,R.mx);
			mn=min(mn,R.mn);
		}
		printf("%d\n",mx-mn+1);
	}
}
int main() {
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}