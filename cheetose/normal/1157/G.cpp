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

int a[200][200],r[200],c[200],t[200];
int n,m;
bool ok(){
	int cc=0;
	fup(i,1,n-1,1){
		int ch=0;
		fup(j,1,m-1,1){
			if(a[i][j]!=a[i][j-1])ch++;
		}
		if(ch>=2)return 0;
		if(ch==0)t[i]=a[i][0];
		else t[i]=2+a[i][0],cc++;
	}
	if(cc>=2)return 0;
	bool tmp=0;
	fup(i,1,n-1,1){
		if(!tmp){
			if(t[i]>=2){
				int tt=t[i]&1;
				if(tt==1)r[i]=1;
				else r[i]=0;
				tmp=1;
			}else{
				if(t[i]==1)r[i]=1;
				else r[i]=0;
			}
		}else{
			if(t[i]==0)r[i]=1;
			else r[i]=0;
		}
	}
	return 1;
}
bool ok2(){
	int cc=0;
	fup(i,1,n-1,1){
		int ch=0;
		fup(j,1,m-1,1){
			if(a[i][j]!=a[i][j-1])return 0;
		}
		if(a[i][0]==0)r[i]=1;
		else r[i]=0;
	}
	return 1;
}
int main(){
	scanf("%d%d",&n,&m);
	fup(i,0,n-1,1)fup(j,0,m-1,1)scanf("%d",&a[i][j]);
	fup(j,0,m-1,1){
		if(a[0][j]==1){
			c[j]=1;
			fup(i,0,n-1,1)a[i][j]^=1;
		}
	}
	if(n==1){
		puts("YES");
		puts("0");
		fup(i,0,m-1,1)printf("%d",c[i]);
		return 0;
	}
	if(ok()){
		puts("YES");
		fup(i,0,n-1,1)printf("%d",r[i]);
		puts("");
		fup(i,0,m-1,1)printf("%d",c[i]);
		puts("");
		return 0;
	}
	fdn(j,m-1,0,1){
		c[j]^=1;
		fup(i,0,n-1,1){
			a[i][j]^=1;
		}
		if(ok2()){
			puts("YES");
			fup(i,0,n-1,1)printf("%d",r[i]);
			puts("");
			fup(i,0,m-1,1)printf("%d",c[i]);
			puts("");
			return 0;
		}
	}
	puts("NO");
}