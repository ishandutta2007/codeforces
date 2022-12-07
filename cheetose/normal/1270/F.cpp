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
typedef vector<double> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef tuple<int, int, int> iii;
typedef tuple<int,int,int,int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const int MOD = 998244353;
ll POW(ll a, ll b, ll MMM=MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[]={2,2,-2,-2,1,1,-1,-1},ddy[]={1,-1,1,-1,2,-2,2,-2};

char s[200005];
int p[200005],ss[200005];
int main() {
	scanf("%s",s+1);
	int n=strlen(s+1);
	int m=sqrt(n);
	Vi vv;
	int now=0;
	fup(i,1,n,1){
		p[i]=now;
		ss[i]=ss[i-1];
		if(s[i]=='1'){
			ss[i]++;
			vv.pb(i);
			now++;
		}
	}
	vv.pb(n+1);
	if(vv.empty())return !printf("0");
	Vi cnt(n*m+5);
	ll ans=0;
	fup(k,1,m,1){
		stack<int> st;
		Vi tmp;
		int t=0;
		fup(i,0,n,1){
			if(ss[i]!=ss[t]){
				while(!tmp.empty()){
					cnt[tmp.back()]++;
					tmp.pop_back();
				}
			}
			ans+=cnt[k*ss[i]-i+n];
			tmp.pb(k*ss[i]-i+n);
			st.push(k*ss[i]-i+n);
		}
		while(!st.empty()){
			cnt[st.top()]=0;
			st.pop();
		}
	}
	fup(i,1,n,1){
		for(int j=1;j<=n/m && p[i]+j<=now;j++){
			int l=vv[p[i]+j-1]-i+1;
			int r=vv[p[i]+j]-i;
			l=max(l,j*(m+1));
			if(l<=r)ans+=r/j-(l-1)/j;
		}
	}
	printf("%lld\n",ans);
}