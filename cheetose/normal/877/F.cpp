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
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[]={2,2,-2,-2,1,1,-1,-1},ddy[]={1,-1,1,-1,2,-2,2,-2};

Vll vv={0};
int a[100001],t[100001],cnt[100001],n,sz,N;
ll b[100001],k;
ll res,ans[100000];
int preL[100001],preR[100001];
struct query {
	int l, r, i;
	query() :query(0, 0, 0) {}
	query(int L, int R, int I) :l(L), r(R), i(I) {}
	bool operator < (const query& Q)
	{
		int lg = r / sz, rg = Q.r / sz;
		return lg == rg ? l < Q.l : lg < rg;
	}
}q[100000];
void Radd(int i)
{
	int j=preR[i];
	if(j!=-1)res+=cnt[j];
	cnt[t[i]]++;
}
void Rerase(int i)
{
	cnt[t[i]]--;
	int j=preR[i];
	if(j!=-1)res-=cnt[j];
}
void Ladd(int i)
{
	int j=preL[i];
	if(j!=-1)res+=cnt[j];
	cnt[t[i]]++;
}
void Lerase(int i)
{
	cnt[t[i]]--;
	int j=preL[i];
	if(j!=-1)res-=cnt[j];
}
int main() {
	scanf("%d%lld",&n,&k);
	sz=sqrt(n);
	fup(i,1,n,1)scanf("%d",a+i);
	fup(i,1,n,1){
		scanf("%lld",b+i);
		if(a[i]==2)b[i]*=-1;
		b[i]+=b[i-1];
		vv.pb(b[i]);
	}
	sort(ALL(vv));vv.resize(unique(ALL(vv))-vv.begin());
	N=vv.size();
	fup(i,0,n,1){
		t[i]=lower_bound(ALL(vv),b[i])-vv.begin();
	}
	fup(i,0,n,1){
		int j=lower_bound(ALL(vv),b[i]-k)-vv.begin();
		if(j<N && vv[j]==b[i]-k)preR[i]=j;
		else preR[i]=-1;
		j=lower_bound(ALL(vv),b[i]+k)-vv.begin();
		if(j<N && vv[j]==b[i]+k)preL[i]=j;
		else preL[i]=-1;
		
	}
	int Q;
	scanf("%d",&Q);
	fup(i,0,Q-1,1){
		int L,R;
		scanf("%d%d",&L,&R);
		q[i]=query(L-1,R,i);
	}
	sort(q,q+Q);
	int L=0,R=0;
	Radd(0);
	fup(i,0,Q-1,1){
		int nl = q[i].l, nr = q[i].r;
		if (nr > R)
		{
			for (int k = R + 1; k <= nr; k++)
				Radd(k);
		}
		if (nl < L)
		{
			for (int k = L - 1; k >= nl; k--)
				Ladd(k);
		}
		if (nr<R)
		{
			for (int k = R; k > nr; k--)
				Rerase(k);
		}
		if (nl > L)
		{
			for (int k = L; k < nl; k++)
				Lerase(k);
		}
		ans[q[i].i] = res;
		L = nl, R = nr;
	}
	fup(i,0,Q-1,1)printf("%lld\n",ans[i]);
}