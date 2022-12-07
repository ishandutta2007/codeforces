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
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[]={2,2,-2,-2,1,1,-1,-1},ddy[]={1,-1,1,-1,2,-2,2,-2};

ll tree[1050000];

void init(int node,int S,int E){
	tree[node]=-INF;
	if(S==E){
		if(S==0)tree[node]=0;
		return;
	}
	int M=S+E>>1;
	init(node<<1,S,M);
	init(node<<1|1,M+1,E);
	tree[node]=max(tree[node<<1],tree[node<<1|1]);
}
void upd(int node, int S, int E, int k, ll dif)
{
	if (S == E){
		tree[node]=dif;
		return;
	}
	if (k <= (S + E) / 2)upd(node * 2, S, (S + E) / 2, k, dif);
	else upd(node * 2 + 1, (S + E) / 2 + 1, E, k, dif);
	tree[node]=max(tree[node<<1],tree[node<<1|1]);
}

ll find(int node, int S, int E, int i, int j)
{
	if (i > E || j < S)return -INF;
	if (i <= S && j >= E)return tree[node];
	return max(find(node * 2, S, (S + E) / 2, i, j), find(node * 2 + 1, (S + E) / 2 + 1, E, i, j));
}
ll s[400005],t[400005];
int main(){
	int n;
	ll k;
	scanf("%d%lld",&n,&k);
	fup(i,1,2*n-1,1)scanf("%lld",s+i),s[i]+=s[i-1];
	int j=0;
	init(1,0,n);
	fup(i,1,n,1){
		while(j<i&&s[i*2-1]-s[2*j]>k)j++;
		if(j>0)t[i]=t[j-1]+k;
		if(j<i)t[i]=max(t[i],s[i*2-1]+find(1,0,n,j,i-1));
		upd(1,0,n,i,t[i]-s[2*i]);
	}
	printf("%lld",t[n]);
}