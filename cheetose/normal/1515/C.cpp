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
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

Pi a[100000];
int ans[100000],sum[100001];
void solve(){
	int n,m,x;
	scanf("%d%d%d",&n,&m,&x);
	fup(i,1,m,1)sum[i]=0;
	priority_queue<Pi,VPi,greater<Pi>> q;
	fup(i,0,n-1,1){
		scanf("%d",&a[i].X);
		a[i].Y=i;
	}
	fup(i,1,m,1)q.push({0,i});
	sort(a,a+n);
	fdn(i,n-1,0,1){
		Pi p=q.top();
		q.pop();
		ans[a[i].Y]=p.Y;
		p.X+=a[i].X;
		sum[p.Y]+=a[i].X;
		q.push(p);
	}
	if((*max_element(sum+1,sum+m+1))-(*min_element(sum+1,sum+m+1))>x){
		puts("NO");
		return;
	}
	puts("YES");
	fup(i,0,n-1,1)printf("%d ",ans[i]);
	puts("");
}
int main() {
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}