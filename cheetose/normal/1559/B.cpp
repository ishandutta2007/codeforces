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

char s[105],t[105];
int d[105][2];
int n;
int go(int N,int k){
	if(N==n)return 0;
	int &ret=d[N][k];
	if(~ret)return ret;
	ret=INF;
	if(s[N]!='R')ret=min(ret,(k==0)+go(N+1,0));
	if(s[N]!='B')ret=min(ret,(k==1)+go(N+1,1));
	return ret;
}
void track(int N,int k){
	if(N==n)return;
	int ret=go(N,k);
	if(s[N]!='R' && ret==(k==0)+go(N+1,0)){
		t[N]='B';
		track(N+1,0);
		return;
	}else{
		t[N]='R';
		track(N+1,1);
		return;
	}
}
void solve(){
	MEM_1(d);
	scanf("%d%s",&n,s);
	t[n]=0;
	int ans=INF;
	if(s[0]!='R')ans=min(ans,go(1,0));
	if(s[0]!='B')ans=min(ans,go(1,1));
	if(s[0]!='R' && ans==go(1,0)){
		t[0]='B';
		track(1,0);
		printf("%s\n",t);
		return;
	}else{
		t[0]='R';
		track(1,1);
		printf("%s\n",t);
		return;
	}
}
int main() {
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}