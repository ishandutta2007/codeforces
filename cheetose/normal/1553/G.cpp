#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define y0 y12
#define y1 y22
#define INF 1987654321987654321
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
typedef pair<ld, ld> Pd;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<ld> Vd;
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
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

Vi v[1000002];
int a[150005];
int p[1000002];
set<int> S[1000002];
int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
void merge(int x,int y){p[find(x)]=find(y);}
int main() {
	fup(i,2,1000001,1){
		if(v[i].size())continue;
		fup(j,i,1000001,i){
			v[j].pb(i);
		}
	}
	iota(p,p+1000002,0);
	int n,q;
	scanf("%d%d",&n,&q);
	fup(i,1,n,1){
		scanf("%d",a+i);
		fup(j,1,(int)v[a[i]].size()-1,1){
			merge(v[a[i]][j-1],v[a[i]][j]);
		}
	}
	fup(i,1,n,1){
		int b=a[i]+1;
		for(int x:v[b]){
			for(int y:v[b]){
				if(find(x)==find(y))continue;
				S[find(x)].insert(find(y));
			}
		}
		for(int x:v[a[i]]){
			for(int y:v[b]){
				if(find(x)==find(y))continue;
				S[find(x)].insert(find(y));
				S[find(y)].insert(find(x));
			}
		}
	}
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		x=find(v[a[x]][0]),y=find(v[a[y]][0]);
		if(x==y)puts("0");
		else if(S[x].find(y)!=S[x].end())puts("1");
		else puts("2");
	}
}