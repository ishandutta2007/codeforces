#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define eb emplace_back
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

string s[100][100];
bool chk[100];
int n;
Vi v[100];
void dfs1(int N,int p,VPi &vv){
	fup(i,0,n-1,1){
		if(!chk[i] && s[p][i][N]=='1'){
			chk[i]=1;
			vv.pb({N,i});
			dfs1(i,N,vv);
		}
	}
}
int d[100][100];
void dfs2(int N,int now,int D=0,int p=-1){
	d[N][now]=D;
	for(int next:v[now]){
		if(next==p)continue;
		dfs2(N,next,D+1,now);
	}
}
void solve(){
	cin>>n;
	fup(i,0,n-1,1){
		fup(j,i+1,n-1,1){
			cin>>s[i][j];
			s[j][i]=s[i][j];
		}
	}
	fup(i,1,n-1,1){
		fup(j,0,n-1,1)chk[j]=0;
		chk[0]=chk[i]=1;
		VPi vv;
		vv.pb({0,i});
		dfs1(0,i,vv);
		dfs1(i,0,vv);
		if(vv.size()!=n-1)continue;
		fup(j,0,n-1,1)v[j].clear();
		for(auto [x,y]:vv){
			v[x].pb(y);
			v[y].pb(x);
		}
		bool ok=1;
		fup(j,0,n-1,1)dfs2(j,j);
		fup(ii,0,n-1,1){
			fup(jj,ii+1,n-1,1){
				fup(kk,0,n-1,1){
					if((s[ii][jj][kk]=='1' && d[ii][kk]!=d[jj][kk]) || (s[ii][jj][kk]=='0' && d[ii][kk]==d[jj][kk]))ok=0;
				}
			}
		}
		if(ok){
		    cout<<"Yes\n";
			for(auto [x,y]:vv)cout<<x+1<<' '<<y+1<<'\n';
			return;
		}
	}
	cout<<"No\n";
}
int main(){
	SYNC;
	int tc;
	cin>>tc;
	while(tc--)solve();
}