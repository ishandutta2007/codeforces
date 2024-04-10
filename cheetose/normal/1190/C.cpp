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

char s[100005];
int sum[2][100005],L[2][100005],R[2][100005];
int main(){
	int n,k;
	scanf("%d%d%s",&n,&k,s+1);
	if(n==k)return !printf("tokitsukaze\n");
	s[0]='2',s[n+1]='2';
	fup(i,1,n,1){
		sum[0][i]=sum[0][i-1];
		sum[1][i]=sum[1][i-1];
		sum[s[i]-'0'][i]++;
	}
	fup(i,k,n,1){
		fup(j,0,1,1)
			if(sum[j][n]-sum[j][i]+sum[j][i-k]+k==n)return !printf("tokitsukaze\n");
	}
	int t[2]={n+1,n+1};
	fdn(i,n,1,1){
		t[s[i]-'0']=i;
		R[0][i]=t[0],R[1][i]=t[1];
	}
	t[0]=t[1]=0;
	fup(i,1,n,1){
		t[s[i]-'0']=i;
		L[0][i]=t[0],L[1][i]=t[1];
	}
	bool ok=1;
	fup(i,k,n,1){
		fup(j,0,1,1){
			int l1=R[j][1],r1=L[j][i-k];
			if(l1>i-k)l1=n+1,r1=0;
			int l2=R[j][i+1],r2=L[j][n];
			if(r2<=i)l2=n+1,r2=0;
			int len=max(r1,r2)-min(l1,l2)+1;
			if(k<len)ok=0;
		}
	}
	puts(ok?"quailty":"once again");
}