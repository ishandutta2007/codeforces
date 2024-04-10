#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

int n,m;
string ans;
int main() {
	scanf("%d%d",&n,&m);
	rep(i,0,m-1) ans.pb('L');
	rep(i,0,n-1) ans.pb('U');
	rep(i,0,n) {
		if (i%2==0) {
			rep(j,0,m-1) ans.pb('R');
		} else {
			rep(j,0,m-1) ans.pb('L');
		}
		if (i!=n-1) ans.pb('D');
	}
	printf("%d\n",SZ(ans));
	printf("%s\n",ans.c_str());
}