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
const int MOD = 500000009;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

int cc[200000];
void solve(){
	int n,m;
	scanf("%d%d",&n,&m);
	vector<Vi> a(n,Vi(m));
	auto b=a;
	fup(i,0,n-1,1)fup(j,0,m-1,1)scanf("%d",&a[i][j]);
	fup(i,0,n-1,1){
		int c=0;
		fup(j,0,m-2,1){
			if(a[i][j]>a[i][j+1]){
				c++;
				b[i][j]=1;
			}
		}
		if(c>=3){
			puts("-1");
			return;
		}
		cc[i]=c;
	}
	fup(i,0,n-1,1){
		if(cc[i]==2){
			Vi v;
			fup(j,0,m-2,1){
				if(b[i][j]){
					if(v.empty())v.pb(j);
					else v.pb(j+1);
				}
			}
			fup(ii,0,n-1,1){
				swap(a[ii][v[0]],a[ii][v[1]]);
				fup(j,1,m-1,1){
					if(a[ii][j]<a[ii][j-1]){
						puts("-1");
						return;
					}
				}
			}
			printf("%d %d\n",v[0]+1,v[1]+1);
			return;
		}
	}
	fup(i,0,n-1,1){
		if(cc[i]==1){
			Vi v;
			fup(j,0,m-2,1){
				if(b[i][j]){
					int jj=j;
					while(jj-1>=0 && a[i][jj-1]==a[i][jj])jj--;
					v.pb(jj);
					jj=j+1;
					while(jj+1<m && a[i][jj+1]==a[i][jj])jj++;
					v.pb(jj);
				}
			}
			fup(ii,0,n-1,1){
				swap(a[ii][v[0]],a[ii][v[1]]);
				fup(j,1,m-1,1){
					if(a[ii][j]<a[ii][j-1]){
						puts("-1");
						return;
					}
				}
			}
			printf("%d %d\n",v[0]+1,v[1]+1);
			return;
		}
	}
	puts("1 1");
}
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}