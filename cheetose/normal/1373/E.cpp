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
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[]={2,2,-2,-2,1,1,-1,-1},ddy[]={1,-1,1,-1,2,-2,2,-2};

int s[700011];
int ans[151]={-1,0,-1,1,-1,2,-1,3,-1,4,9,5,19,6,29,7,39,8,49,18,59,28,69,38,79,48,89,58,189,68,289,78,389,88,489,98,589,198,689,298,789,398,889,498,989,598,1989,698,2989,798,3989,898,4989,998,5989,1998,6989,2998,7989,3998,8989,4998,9989,5998,19989,6998,29989,7998,39989,8998,49989,9998,59989,19998,69989,29998,79989,39998,89989,49998,99989,59998,199989,69998,299989,79998,399989,89998,499989,99998,599989,199998,699989,299998,799989,399998,899989,499998,999989,599998,1999989,699998,2999989,799998,3999989,899998,4999989,999998,5999989,1999998,6999989,2999998,7999989,3999998,8999989,4999998,9999989,5999998,19999989,6999998,29999989,7999998,39999989,8999998,49999989,9999998,59999989,19999998,69999989,29999998,79999989,39999998,89999989,49999998,99999989,59999998,199999989,69999998,299999989,79999998,399999989,89999998,499999989,99999998,599999989,199999998,699999989,299999998,799999989,399999998,899999989};
void solve(){
	int n,k;
	scanf("%d%d",&n,&k);
	if(k>=2){
		fup(i,0,700000,1){
			int S=s[i+k];
			if(i)S-=s[i-1];
			if(S==n){
				printf("%d\n",i);
				return;
			}
		}
		puts("-1");
		return;
	}
	if(k==0){
		stack<int> st;
		while(n){
			st.push(min(9,n));
			n-=min(9,n);
		}
		while(!st.empty()){
			printf("%d",st.top());
			st.pop();
		}
		puts("");
		return;
	}
	printf("%d\n",ans[n]);
}
int g(int x){
	int r=0;
	while(x){
		r+=x%10;
		x/=10;
	}
	return r;
}
int main(){
	int tc;
	scanf("%d",&tc);
	fup(i,1,700010,1){
		s[i]=s[i-1]+g(i);
	}
	while(tc--){solve();
	}
}