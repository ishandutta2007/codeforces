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

char s[15];
int a[100001],b[100001];
void solve(){
	int n;
	scanf("%d",&n);
	int s1=0,s2=0;
	fup(i,1,n,1)scanf("%d",a+i);
	fup(i,1,n,1)scanf("%d",b+i);
	sort(b+1,b+n+1);
	sort(a+1,a+n+1);
	fup(i,1,n,1){
		s1+=a[i],s2+=b[i];
		if(i%4==0)s1-=a[i/4],s2-=b[i/4];
	}
	if(s1>=s2){
		puts("0");
		return;
	}
	int j=n/4;
	fup(i,n+1,2*n,1){
		s1+=100;
		if(i%4==0)s1-=a[i/4];
		else if(j>0){
			s2+=b[j--];
		}
		if(s1>=s2){
			printf("%d\n",i-n);
			return;
		}
	}
}
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}