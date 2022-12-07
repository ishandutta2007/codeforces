#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define y0 y12
#define y1 y22
#define INF 1987654321
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

char s[2][200005];
int t[200005],l[2][200005],r[2][200005];
void solve(){
	int n;
	scanf("%d",&n);
	fup(i,0,1,1)scanf("%s",s[i]+1);
	fup(i,1,n,1){
		t[i]=t[i-1];
		if(s[0][i]=='*' || s[1][i]=='*')t[i]++;
	}
	int tot=t[n];
	fup(i,0,n+1,1)l[0][i]=l[1][i]=r[0][i]=r[1][i]=0;
	fup(j,1,n,1){
		fup(i,0,1,1){
			if(t[j-1]){
				if(s[i^1][j]=='*'){
					l[i][j]=min(l[i^1][j-1]+2,l[i][j-1]+2);
				}else l[i][j]=min(l[i^1][j-1]+2,l[i][j-1]+1);
			}else{
				if(s[i^1][j]=='*')l[i][j]=1;
			}
		}
	}
	fdn(j,n,1,1){
		fup(i,0,1,1){
			if(tot-t[j]){
				if(s[i^1][j]=='*'){
					r[i][j]=min(r[i^1][j+1]+2,r[i][j+1]+2);
				}else r[i][j]=min(r[i^1][j+1]+2,r[i][j+1]+1);
			}else{
				if(s[i^1][j]=='*')r[i][j]=1;
			}
		}
	}
	int ans=INF;
	fup(j,0,n-1,1){
		fup(i1,0,1,1){
			fup(i2,0,1,1){
				int tmp=l[i1][j]+r[i2][j+1];
				if(t[j] && tot-t[j]){
					tmp+=1+(i1^i2);
				}
				ans=min(ans,tmp);
			}
		}
	}
	printf("%d\n",ans);
}
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}