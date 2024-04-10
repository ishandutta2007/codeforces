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

struct line{  // y = a*x + b
	ll a,b;
};
 
struct convexhull_trick{
	int s=0,e=0;
	line deq[200005];
	double cross(int a, int b) {
		return 1.0 * (deq[a].b - deq[b].b) / (deq[b].a - deq[a].a);
	}
	void insert(line v){
		deq[e] = v;
		while(s+1<e && cross(e - 2, e - 1) < cross(e - 1, e)){
			deq[e-1] = deq[e];
			e--;
		}
		e++;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
	}
	ll query(ll x){
		int l = 0, r = e - 1;
		while (l != r) {
			int m = (l + r) / 2;
			if (cross(m, m + 1) >= x) l = m + 1;
			else r = m;
		}
		return deq[l].a*x+deq[l].b;
	}
	void clear(){s = e = 0;}
}cht;
ll a[200000],ans;
ll b[200000];
void f(int S,int E){
	if(S==E){
		ans=max(ans,a[S]);
		return;
	}
	int M=S+E>>1;
	ll now=0,t=0;
	fdn(i,M,S,1){
		t+=a[i];
		now+=t;
		b[i]=now;
	}
	cht.clear();
	fup(i,S,M,1){
		cht.insert({M-i+1,b[i]});
	}
	ans=max(ans,cht.query(0));
	now=t=0;
	fup(i,M+1,E,1){
		t+=a[i];
		now+=a[i]*(i-M);
		ans=max(ans,cht.query(t)+now);
	}
	f(S,M);f(M+1,E);
}
int main(){
	int n;
	scanf("%d",&n);
	fup(i,0,n-1,1)scanf("%lld",a+i);
	f(0,n-1);
	printf("%lld\n",ans);
}