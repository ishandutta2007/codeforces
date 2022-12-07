#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<string>
#include<stack>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<cstring>
#include<complex>
#include<cmath>
#include<iomanip>
#include<numeric>
#include<algorithm>
#include<list>
#include<functional>
#include<cassert>
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
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

struct line{  // y = a*x + b
    ll a,b;
};
 
struct convexhull_trick{
    int s=0,e=0;
    int idx[1000005];
    line deq[1000005];
    double cross(int a, int b) {
        return 1.0 * (deq[a].b - deq[b].b) / (deq[b].a - deq[a].a);
    }
    void insert(line v,int line_idx){
        deq[e] = v;
        idx[e] = line_idx;
        while(s+1<e && cross(e - 2, e - 1) > cross(e - 1, e)){
            deq[e-1] = deq[e];
            idx[e-1] = idx[e];
            e--;
        }
        e++;
    }
    Pll query(ll x){  // query  
        while(s+1<e && deq[s+1].b - deq[s].b >= x * (deq[s].a - deq[s+1].a))
            s++;
        return Pll(deq[s].a*x+deq[s].b,idx[s]);
    }
    Pll query2(ll x){ //  query
        int l = 0, r = e - 1;
        while (l != r) {
            int m = (l + r) / 2;
            if (cross(m, m + 1) <= x) l = m + 1;
            else r = m;
        }
        return Pll(deq[l].a*x+deq[l].b,idx[l]);
    }
    void clear(){s = e = 0;}
}cht;
 
struct sqr{
	ll x,y,z;
	bool operator <(sqr &o)const{
		return x<o.x;
	}
}a[1000005];
int main() {
	int n;
	scanf("%d",&n);
	fup(i,0,n-1,1)
		scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].z),a[i].z=a[i].x*a[i].y-a[i].z;
	sort(a,a+n);
	ll ans=0;
	line L;
	L.a=0,L.b=0;
	cht.insert(L,-1);
	fup(i,0,n-1,1)
	{
		ll w=a[i].z+cht.query(-a[i].y).X;
		ans=max(ans,w);
		L.a=a[i].x,L.b=w;
		cht.insert(L,i);
	}
	printf("%lld",ans);
}