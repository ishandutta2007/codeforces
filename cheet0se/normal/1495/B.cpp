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
#define MEM0(a) memset((a),0,sizeof(a))
#define MEM_1(a) memset((a),-1,sizeof(a))
#define ALL(a) a.begin(),a.end()
#define COMPRESS(a) sort(ALL(a));a.resize(unique(ALL(a))-a.begin())
#define SYNC ios_base::sync_with_stdio(false);cin.tie(0)
using namespace std;
typedef long long ll;
//typedef long double ld;
typedef double db;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> Pi;
typedef pair<ll, ll> Pll;
//typedef pair<ld, ld> Pd;
typedef vector<int> Vi;
typedef vector<ll> Vll;
//typedef vector<ld> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
//typedef vector<Pd> VPd;
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

int a[100002];
int ld[100002],li[100002],rd[100002],ri[100002];
int mxr[100002],mxl[100002];
int main(){
	int n;
	scanf("%d",&n);
	fup(i,0,n-1,1)scanf("%d",a+i);
	fup(i,1,n-1,1){
		if(a[i]>a[i-1])ld[i]=ld[i-1]+1;
		if(a[i]<a[i-1])li[i]=li[i-1]+1;
	}
	fdn(i,n-2,0,1){
		if(a[i]>a[i+1])rd[i]=rd[i+1]+1;
		if(a[i]<a[i+1])ri[i]=ri[i+1]+1;
	}
	fup(i,1,n-1,1){
		mxl[i]=max(mxl[i-1],ld[i]);
	}
	fdn(i,n-2,0,1){
		mxr[i]=max(mxr[i+1],rd[i]);
	}
	int ans=0;
	fup(i,0,n-1,1){
		if(ld[i]==0 || rd[i]==0)continue;
		bool ok=1;
		if(max(ld[i],rd[i])<=max(mxl[max(0,i-ld[i]-1)],mxr[i+rd[i]+1]))ok=0;
		if(ld[i]&1){
			int t=i-ld[i];
			if(rd[i]<=max(li[t],ri[t]))ok=0;
		}else{
			int t=i-ld[i];
			if(ld[i]<=li[t] && rd[i]<=max(li[t],ri[t]))ok=0;
			if(rd[i]<=ld[i]-1)ok=0;
		}
		if(rd[i]&1){
			int t=i+rd[i];
			if(ld[i]<=max(li[t],ri[t]))ok=0;
		}else{
			int t=i+rd[i];
			if(rd[i]<=ri[t] && ld[i]<=max(li[t],ri[t]))ok=0;
			if(ld[i]<=rd[i]-1)ok=0;
		}
		if(ok)ans++;
	}
	printf("%d\n",ans);
}