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

Vi v[400001];
int num[400001], low[400001], sn[400001], ind[400001];
bool chk[400001];
Vi st;
int cnt, SN;
void dfs(int n){
	chk[n] = 1;
	st.pb(n);
	num[n] = ++cnt;
	low[n] = cnt;
	for (int next : v[n]){
		if (num[next] == 0){
			dfs(next);
			low[n] = min(low[n], low[next]);
		}
		else if (chk[next])
			low[n] = min(low[n], num[next]);
	}
	if (num[n] == low[n]){
		while (!st.empty()){
			int x = st.back();
			st.pop_back();
			sn[x] = SN;
			chk[x] = 0;
			if (n == x)
				break;
		}
		SN++;
	}
}
int n,m;
inline int z(int x,int y){
	return x*m+y;
}
int main(){
	SYNC;
	cin>>n>>m;
	vector<string> s(n);
	fup(i,0,n-1,1)cin>>s[i];
	vector<Vi> a(n,Vi(m));
	fup(j,0,m-1,1){
		fdn(i,n-1,0,1){
			if(i>0 && s[i][j]=='#' && s[i-1][j]=='#')v[z(i,j)].pb(z(i-1,j));
			if(i==n-1){
				if(s[i][j]=='#')a[i][j]=z(i,j);
				else a[i][j]=-1;
			}else{
				a[i][j]=a[i+1][j];
				if(s[i][j]=='#' && a[i][j]!=-1){
					v[z(i,j)].pb(a[i][j]);
				}
				if(s[i][j]=='#')a[i][j]=z(i,j);
			}
		}
	}
	fup(i,0,n-1,1){
		fup(j,0,m-1,1){
			if(s[i][j]=='.')continue;
			if(j>0 && a[i][j-1]!=-1)v[z(i,j)].pb(a[i][j-1]);
			if(j<m-1 && a[i][j+1]!=-1)v[z(i,j)].pb(a[i][j+1]);
		}
	}
	fup(i,0,n-1,1){
		fup(j,0,m-1,1){
			if(s[i][j]=='#' && !num[z(i,j)])dfs(z(i,j));
		}
	}
	fup(x,0,n*m-1,1){
		for(int y:v[x]){
			if(sn[x]!=sn[y])ind[sn[y]]++;
		}
	}
	int ans=0;
	fup(i,0,SN-1,1)if(ind[i]==0)ans++;
	printf("%d\n",ans);
}