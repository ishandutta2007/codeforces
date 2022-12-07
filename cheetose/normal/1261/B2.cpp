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
const ll MOD = 10003;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[]={2,2,-2,-2,1,1,-1,-1},ddy[]={1,-1,1,-1,2,-2,2,-2};

int a[200000],b[200000],ans[200000];
iii query[200000];
int tree[524288];
void upd(int node, int S, int E, int k, int dif)
{
	tree[node] += dif;
	if (S == E)return;
	if (k <= (S + E) / 2)upd(node * 2, S, (S + E) / 2, k, dif);
	else upd(node * 2 + 1, (S + E) / 2 + 1, E, k, dif);
}
int findK(int node, int S, int E, int k)
{
	if (S == E)return S;
	if (k <= tree[node * 2])return findK(node * 2, S, (S + E) / 2, k);
	return findK(node * 2 + 1, (S + E) / 2 + 1, E, k - tree[node * 2]);
}
int main(){
	int n;
	scanf("%d",&n);
	fup(i,0,n-1,1)
	{
		b[i]=i;
		scanf("%d",a+i);
	}
	sort(b,b+n,[&](int x,int y){
		if(a[x]!=a[y])return a[x]>a[y];
		return x<y;
	});
	int q;
	scanf("%d",&q);
	fup(i,0,q-1,1)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		query[i]=iii(x,y,i);
	}
	sort(query,query+q);
	int j=0;
	fup(k,0,q-1,1)
	{
		int x,t,Q;
		tie(x,t,Q)=query[k];
		while(j<n && j<x)
		{
			upd(1,0,n-1,b[j],1);
			j++;
		}
		ans[Q]=findK(1,0,n-1,t);
	}
	fup(i,0,q-1,1)printf("%d\n",a[ans[i]]);
}