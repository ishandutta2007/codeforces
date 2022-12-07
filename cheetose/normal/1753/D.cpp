#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define X first
#define Y second
#define y0 y12
#define y1 y22
#define INF 987654321987654321
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
const int MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

int n,m,p,q;
string s[300005];
VPi v[300005];
inline int z(int x,int y){return x*m+y;}
ll dist[300005];
bool chk[300005];
int main(){
	fill(dist,dist+300005,INF);
	SYNC;
	cin>>n>>m>>p>>q;
	fup(i,0,n-1,1)cin>>s[i];
	fup(x,0,n-1,1){
		fup(y,0,m-1,1){
			if(s[x][y]=='L'){
				if(y+2<m){
					v[z(x,y+2)].eb(z(x,y),q);
				}
				if(x>0 && s[x-1][y+1]!='#'){
					v[z(x-1,y+1)].eb(z(x,y),p);
				}
				if(x+1<n && s[x+1][y+1]!='#'){
					v[z(x+1,y+1)].eb(z(x,y),p);
				}
			}else if(s[x][y]=='R'){
				if(y-2>=0){
					v[z(x,y-2)].eb(z(x,y),q);
				}
				if(x>0 && s[x-1][y-1]!='#'){
					v[z(x-1,y-1)].eb(z(x,y),p);
				}
				if(x+1<n && s[x+1][y-1]!='#'){
					v[z(x+1,y-1)].eb(z(x,y),p);
				}
			}else if(s[x][y]=='U'){
				if(x+2<n){
					v[z(x+2,y)].eb(z(x,y),q);
				}
				if(y>0 && s[x+1][y-1]!='#'){
					v[z(x+1,y-1)].eb(z(x,y),p);
				}
				if(y+1<m && s[x+1][y+1]!='#'){
					v[z(x+1,y+1)].eb(z(x,y),p);
				}
			}else if(s[x][y]=='D'){
				if(x-2>=0){
					v[z(x-2,y)].eb(z(x,y),q);
				}
				if(y>0 && s[x-1][y-1]!='#'){
					v[z(x-1,y-1)].eb(z(x,y),p);
				}
				if(y+1<m && s[x-1][y+1]!='#'){
					v[z(x-1,y+1)].eb(z(x,y),p);
				}
			}
		}
	}
	priority_queue<Pll> q;
	fup(i,0,n-1,1){
		fup(j,0,m-1,1){
			if(s[i][j]=='.'){
				int Z=z(i,j);
				q.push({0,Z});
				dist[Z]=0;
			}
		}
	}
	while(!q.empty()){
		int x=q.top().Y;
		q.pop();
		if(chk[x])continue;
		chk[x]=1;
		for(auto [next,c]:v[x]){
			if(dist[next]>dist[x]+c){
				dist[next]=dist[x]+c;
				q.push({-dist[next],next});
			}
		}
	}
	ll ans=INF;
	fup(i,0,n-1,1){
		fup(j,0,m-1,1){
			if(j+1<m){
				ans=min(ans,dist[z(i,j)]+dist[z(i,j+1)]);
			}
			if(i+1<n){
				ans=min(ans,dist[z(i,j)]+dist[z(i+1,j)]);
			}
		}
	}
	if(ans==INF)ans=-1;
	printf("%lld\n",ans);
}