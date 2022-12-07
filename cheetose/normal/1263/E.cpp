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
const int MOD = 1000000009;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[]={-1,-2,1,-2,2,-1,2,1},ddy[]={-2,-1,-2,1,-1,2,1,2};

struct Node {
	int lsum, rsum, maxsum, sum, lmin;
};
Node tree[1<<21];
void upd(int node, int S, int E, int i, int k)
{
	if (S == E)
	{
		tree[node].lsum = k;
		tree[node].rsum = k;
		tree[node].maxsum = k;
		tree[node].sum = k;
		tree[node].lmin=k;
		return;
	}
	if (i <= (S + E) / 2)upd(node * 2, S, (S + E) / 2, i, k);
	else upd(node * 2 + 1, (S + E) / 2 + 1, E, i, k);
	tree[node].lsum = max(tree[node * 2].lsum, tree[node * 2].sum + tree[node * 2 + 1].lsum);
	tree[node].rsum = max(tree[node * 2 + 1].rsum, tree[node * 2 + 1].sum + tree[node * 2].rsum);
	tree[node].sum = tree[node * 2].sum + tree[node * 2 + 1].sum;
	tree[node].maxsum = max({ tree[node * 2].maxsum, tree[node * 2 + 1].maxsum, tree[node * 2].rsum + tree[node * 2 + 1].lsum });
	tree[node].lmin=min(tree[node*2].lmin,tree[node*2].sum+tree[node*2+1].lmin);
}
char s[1000005];
int main(){
	int now=0,n;
	scanf("%d%s",&n,s);
	fup(i,0,n-1,1)
	{
		if(s[i]=='L')now=max(now-1,0);
		else if(s[i]=='R')now++;
		else if(s[i]=='(')upd(1,0,n,now,1);
		else if(s[i]==')')upd(1,0,n,now,-1);
		else upd(1,0,n,now,0);
		if(tree[1].lmin<0 || tree[1].sum!=0)printf("-1 ");
		else printf("%d ",tree[1].maxsum);
	}
}