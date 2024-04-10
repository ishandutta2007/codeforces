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
const int MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

char s[600006];
int a[600006];
int main(){
	int n;
	scanf("%d%s",&n,s+1);
	fup(i,1,n,1){
		if(s[i]=='(')a[i]=a[i-1]+1;
		else a[i]=a[i-1]-1;
	}
	if(a[n]!=0){
		return !printf("0\n1 1\n");
	}
	fup(i,1,n,1)a[i+n]=a[i];
	int mn=*min_element(a+1,a+n+1);
	int c=0,ans=0,t1,t2;
	Vi v;
	fup(i,0,n-1,1){
		if(a[i]==mn){
			v.pb(i);
			c++;
		}
	}
	v.pb(v[0]+n);
	fup(i,0,(int)v.size()-2,1){
		int t=0;
		fup(j,v[i]+1,v[i+1]-1,1){
			if(a[j]==mn+1)t++;
		}
		if(t>ans){
			ans=t,t1=v[i]+1,t2=v[i+1];
		}
	}
	v.clear();
	fup(i,0,n-1,1)if(a[i]<=mn+1)v.pb(i);
	v.pb(v[0]+n);
	fup(i,0,(int)v.size()-2,1){
		int t=0;
		fup(j,v[i]+1,v[i+1]-1,1){
			if(a[j]==mn+2)t++;
		}
		if(t+c>ans){
			ans=t+c,t1=v[i]+1,t2=v[i+1];
		}
	}
	if(t1>n)t1-=n;
	if(t2>n)t2-=n;
	printf("%d\n%d %d\n",ans,t1,t2);
}