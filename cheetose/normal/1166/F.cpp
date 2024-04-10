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

int f[100001];
map<int,int> col[100001];
set<int> adj[100001];
int n,m,c,q;
int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
void merge(int x,int y){
	x=find(x),y=find(y);
	if(x==y)return;
	if(adj[x].size()>adj[y].size())swap(x,y);
	f[x]=y;
	while(!adj[x].empty()){
		adj[y].insert(*adj[x].begin());
		adj[x].erase(adj[x].begin());
	}
}
void add(int x,int y,int z){
	if(col[x].count(z))merge(y,col[x][z]);
	else col[x][z]=y;
	if(col[y].count(z))merge(x,col[y][z]);
	else col[y][z]=x;
	adj[find(x)].insert(y);
	adj[find(y)].insert(x);
}
int main(){
	scanf("%d%d%d%d",&n,&m,&c,&q);
	fup(i,1,n,1)f[i]=i;
	while(m--){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
	}
	while(q--){
		char c;
		int x,y,z;
		scanf(" %c%d%d",&c,&x,&y);
		if(c=='+'){
			scanf("%d",&z);
			add(x,y,z);
		}else{
			if(find(x)==find(y) || adj[find(x)].find(y)!=adj[find(x)].end())puts("Yes");
			else puts("No");
		}
	}
}