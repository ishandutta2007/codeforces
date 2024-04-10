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
#define INF 987654321987654321
#define PI 3.141592653589793238462643383279502884
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset(a,0,sizeof(a));
#define MEM_1(a) memset(a,-1,sizeof(a));
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
typedef pair<double, double> Pd;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<double> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

char s[1000005];
struct A{
	int l,r,i;
}q[100000];
int ans[100000];
VPi v;
stack<int> st;

int tree[1000005];
int n;
void upd(int i)
{
	while (i <= n)
	{
		tree[i]++;
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
int main() {
	scanf("%s",s+1);
	int m;
	n=strlen(s+1);
	fup(i,1,n,1)
	{
		if(s[i]=='(')st.push(i);
		else
		{
			if(st.empty())continue;
			v.pb(mp(st.top(),i));
			st.pop();
		}
	}
	int N=v.size();
	sort(ALL(v),[&](Pi p1,Pi p2){return p1.Y<p2.Y;});
	scanf("%d",&m);
	fup(i,0,m-1,1)
	{
		scanf("%d%d",&q[i].l,&q[i].r);
		q[i].i=i;
	}
	sort(q,q+m,[&](A a1,A a2){return a1.r<a2.r;});
	int now=0;
	fup(i,0,m-1,1)
	{
		while(now<N && v[now].Y<=q[i].r)upd(v[now++].X);
		ans[q[i].i]=now-sum(q[i].l-1);
	}
	fup(i,0,m-1,1)printf("%d\n",ans[i]*2);
}