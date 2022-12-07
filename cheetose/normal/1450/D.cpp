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
const int MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

int a[300000];
Vi v[300001];

int tree[300005];
int n;
void upd(int i, int k)
{
	while (i <= n)
	{
		tree[i] += k;
		i += (i&-i);
	}
}
int sum(int i)
{
	int c = 0;
	while (i > 0)
	{
		c += tree[i];
		i -= (i&-i);
	}
	return c;
}
void solve(){
	scanf("%d",&n);
	fup(i,1,n,1)v[i].clear(),tree[i]=0;
	fup(i,0,n-1,1){
		scanf("%d",a+i);
		v[a[i]].pb(i);
	}
	set<int> S;
	S.insert(-1);S.insert(n);
	fup(i,1,n,1){
		if(v[i].empty())continue;
		int tt=0;
		for(int j:v[i]){
			auto it=S.lower_bound(j);
			int r=*it;
			it--;
			int l=*it;
			tt=max(tt,r-l-1);
		}
		upd(1,1);
		upd(min(n+1-i,tt)+1,-1);
		for(int j:v[i])S.insert(j);
	}
	fup(i,1,n,1){
		if(sum(i)==n+1-i)putchar('1');
		else putchar('0');
	}
	puts("");
}
int main() {
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}