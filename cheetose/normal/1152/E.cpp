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
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

Vi vv;
int a[100000][2],cnt[200000];

struct Edge{
    int to, cnt;
    Edge *dual;
    Edge(): Edge(-1, 0){}
    Edge(int to1, int cnt1): to(to1), cnt(cnt1), dual(nullptr){}
};
int degree[200000];
vector<Edge*> v[200000];
bool visited[200000];
int pt[200000];
Vi ans;
void Euler(int N){
	for(;pt[N]<(int)v[N].size();pt[N]++){
		auto *e=v[N][pt[N]];
        if(e->cnt > 0){
            e->cnt--;
            e->dual->cnt--;
            Euler(e->to);
        }
    }
    ans.pb(N);
}

void addedge(int i,int j,int val){
	Edge *e1 = new Edge(j, val), *e2 = new Edge(i, val);
	e1->dual = e2;
	e2->dual = e1;
	v[i].push_back(e1);
	v[j].push_back(e2);
	degree[i] += val;
	degree[j] += val;
}
int main(){
	int n;
	scanf("%d",&n);
	fup(j,0,1,1)fup(i,0,n-2,1)scanf("%d",&a[i][j]),vv.pb(a[i][j]);
	fup(i,0,n-2,1)if(a[i][0]>a[i][1])return !printf("-1");
	sort(ALL(vv));vv.resize(unique(ALL(vv))-vv.begin());
	fup(j,0,1,1)fup(i,0,n-2,1)a[i][j]=lower_bound(ALL(vv),a[i][j])-vv.begin();
	fup(i,0,n-2,1)addedge(a[i][0],a[i][1],1);
	int N=vv.size();
	int cc=0;
	fup(i,0,N-1,1)if(degree[i]&1)cc++;
	if(cc!=0 && cc!=2)return !printf("-1");
	fup(i,0,N-1,1)
	if(degree[i]&1)
	{
		Euler(i);
		if(ans.size()!=n)return !printf("-1");
		for(int x:ans)printf("%d ",vv[x]);
			return 0;
	}
	Euler(0);
	if(ans.size()!=n)return !printf("-1");
	for(int x:ans)printf("%d ",vv[x]);
}