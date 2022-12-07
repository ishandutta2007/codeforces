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

ll p[500005],tree[500005],d[500005],s[500005],tot;
int a[500005],b[500005];
int pos[500005];
int n,m;
void upd(int i, ll k){
	tot+=k;
	while (i <= n+1){
		tree[i] += k;
		i += (i&-i);
	}
}
ll sum(int i){
	ll c = 0;
	while (i > 0){
		c += tree[i];
		i -= (i&-i);
	}
	return tot-c;
}
int main(){
	scanf("%d",&n);
	fup(i,1,n,1)scanf("%d",a+i);
	fup(i,1,n,1)scanf("%lld",p+i);
	scanf("%d",&m);
	fup(i,1,m,1){
		scanf("%d",b+i);
		pos[b[i]]=i;
	}
	fdn(i,n,1,1){
		s[i]=s[i+1];
		if(a[i]>b[m] || p[i]<0)s[i]+=p[i];
	}
	fup(i,1,m,1)d[i]=INF;
	ll ans=INF,tt=0;
	fup(i,1,n,1){
		if(pos[a[i]]){
			int t=pos[a[i]];
			ll res=d[t-1]+sum(b[t-1])+tt;
			if(t==m)ans=min(ans,res+s[i+1]);
			d[t]=min(d[t],res-sum(a[i])-tt-(p[i]<0?p[i]:0));
		}
		if(p[i]>0)upd(a[i],p[i]);
		else tt+=p[i];
	}
	if(ans>=900000000000000000)puts("NO");
	else printf("YES\n%lld\n",ans);
}