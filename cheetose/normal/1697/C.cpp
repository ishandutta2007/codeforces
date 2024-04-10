#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define y0 y12
#define y1 y22
#define INF 11111
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

char s[100005],t[100005];
void solve(){
	int n;
	scanf("%d%s%s",&n,s,t);
	string ss,tt;
	fup(i,0,n-1,1){
		if(s[i]!='b')ss+=s[i];
		if(t[i]!='b')tt+=t[i];
	}
	if(ss!=tt){
		puts("NO");
		return;
	}
	int a=0,b=0;
	Vi v1,v2;
	fup(i,0,n-1,1){
		if(s[i]=='b')a++;
		if(t[i]=='b')b++;
		if(s[i]=='a')v1.pb(a);
		if(t[i]=='a')v2.pb(b);
	}
	int N=v1.size();
	fup(i,0,N-1,1)if(v1[i]>v2[i]){
		puts("NO");
		return;
	}
	a=0,b=0;
	v1.clear();v2.clear();
	fdn(i,n-1,0,1){
		if(s[i]=='b')a++;
		if(t[i]=='b')b++;
		if(s[i]=='c')v1.pb(a);
		if(t[i]=='c')v2.pb(b);
	}
	N=v1.size();
	fup(i,0,N-1,1)if(v1[i]>v2[i]){
		puts("NO");
		return;
	}
	puts("YES");
}
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}