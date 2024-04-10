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

int n,k;
int a[1000001],cnt[1000001];
ll g(int x,int m){
	if(x<=m)return x;
	int c=x/m,d=c+1;
	int b=x%m,aa=m-b;
	return 1LL*c*c*aa+1LL*d*d*b;
}
int main(){
	scanf("%d%ld",&n,&k);
	ll ans=0;
	fup(i,0,n-1,1)scanf("%d",a+i),cnt[i]=1,ans+=1LL*a[i]*a[i];
	priority_queue<Pll> q;
	fup(i,0,n-1,1){
		ll t1=g(a[i],1),t2=g(a[i],2);
		q.push(mp(t1-t2,i));
	}
	k-=n;
	while(k--){
		Pll p=q.top();
		q.pop();
		ans-=p.X;
		int i=p.Y;
		cnt[i]++;
		ll t1=g(a[i],cnt[i]),t2=g(a[i],cnt[i]+1);
		q.push(mp(t1-t2,i));
	}
	printf("%lld\n",ans);
}