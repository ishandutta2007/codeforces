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
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

int a[1000005];
bool chk[1000005];
Vi v;
void dfs(int N,int d=1){
	chk[N]=1;
	int next=a[N];
	if(chk[next])v.pb(d);
	else dfs(next,d+1);
}
bitset<1000001> bs;
int c[1000001],d[1000001];
int cnt[101];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	if(k==0)return !printf("0 0\n");
	fup(i,1,n,1)scanf("%d",a+i);
	fup(i,1,n,1)if(!chk[i])dfs(i);
	int mn=INF,mx=0;
	int t=0;
	for(int x:v)t+=x/2;
	if(k<=t)mx=2*k;
	else{
		int tt=v.size();
		int kk=k-t;
		mx=min(2*t+kk,n);
	}
	bs[0]=true;
	Vi vv;
	for(int x:v){
		if(x<=100)cnt[x]++;
		else vv.pb(x);
	}
	c[0]=1;
	fup(i,2,100,1){
		if(cnt[i]){
			fup(k,0,i-1,1)d[k]=0;
			fup(k,i,1000000,1){
				if(c[k-i])d[k]=1;
				else if(d[k-i]>0 && d[k-i]<cnt[i])d[k]=d[k-i]+1;
				else d[k]=0;
			}
			fup(i,0,1000000,1)if(d[i])c[i]=1;
		}
	}
	for(int x:vv){
		bs|=bs<<x;
	}
	bool ok=0;
	fup(i,0,k,1)if(c[i] && bs[k-i])ok=1;
	if(ok)mn=k;
	else mn=k+1;
	printf("%d %d\n",mn,mx);
}