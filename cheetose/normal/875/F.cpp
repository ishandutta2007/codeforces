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

iii e[200000];
int parent[200002];
int rem[200002];
int find(int x){
	if(parent[x]==x)return x;
	return parent[x]=find(parent[x]);
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	fup(i,1,n,1)parent[i]=i,rem[i]=1;
	fup(i,0,m-1,1){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		e[i]=iii(z,x,y);
	}
	sort(e,e+m);reverse(e,e+m);
	int ans=0;
	fup(i,0,m-1,1){
		auto [z,x,y]=e[i];
		x=find(x),y=find(y);
		if(x==y){
			if(rem[x]>0){
				rem[x]--;
				ans+=z;
			}
		}else if(rem[x]+rem[y]>0){
			rem[x]+=rem[y];
			parent[y]=x;
			rem[x]--;
			ans+=z;
		}
	}
	printf("%d\n",ans);
}