#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define y0 y12
#define y1 y22
#define INF 1987654321987654
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
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM=MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[]={2,2,-2,-2,1,1,-1,-1},ddy[]={1,-1,1,-1,2,-2,2,-2};

string s[300000];
VPi v;
Pi ans;
int n;
bool ok(int k){
	Pi A=mp(v[0].X-k,v[0].Y-k),B=mp(v[0].X+k,v[0].Y+k),D=mp(v[0].Y-v[0].X-k,v[0].Y-v[0].X+k);
	fup(i,1,n-1,1){
		A.X=max(A.X,v[i].X-k);
		A.Y=max(A.Y,v[i].Y-k);
		B.X=min(B.X,v[i].X+k);
		B.Y=min(B.Y,v[i].Y+k);
		D.X=max(D.X,v[i].Y-v[i].X-k);
		D.Y=min(D.Y,v[i].Y-v[i].X+k);
	}
	if(A.X>B.X || A.Y>B.Y || D.X>D.Y)return 0;
	if(B.Y-A.X<D.X || A.Y-B.X>D.Y)return 0;
	if(B.Y-A.X<=D.Y)ans=mp(A.X,B.Y);
	else if(B.Y-D.X<=B.X)ans=mp(B.Y-D.X,B.Y);
	else if(B.Y-B.X>=D.X && B.Y-B.X<=D.Y)ans=mp(B.X,B.Y);
	else ans=mp(B.X,D.Y+B.X);
	return 1;
}
int main(){
	SYNC;
	cin>>n;
	fup(i,0,n-1,1)cin>>s[i];
	fup(i,0,n-1,1){
		int a=0,b=0;
		for(char c:s[i]){
			if(c=='B')a++;
			else b++;
		}
		v.pb(mp(a,b));
	}
	int l=0,r=500000;
	while(l<=r){
		int k=l+r>>1;
		if(ok(k))r=k-1;
		else l=k+1;
	}
	cout<<l<<'\n';
	cout<<string(ans.X,'B')<<string(ans.Y,'N')<<'\n';
}