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
#define INF 987654321
#define PI 3.141592653589793238462643383279502884
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset(a,0,sizeof(a));
#define MEM_1(a) memset(a,-1,sizeof(a));
#define ALL(a) a.begin(),a.end()
#define SYNC ios_base::sync_with_stdio(false);cin.tie(0)
using namespace std;
typedef long long ll;
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
	
int n,a,b,k,f;
int cc;
map<string,int> M;
Pi p[300];
int A[601][601];
int main() {
	SYNC;
	cin>>n>>a>>b>>k>>f;
	string s,t;
	fup(i,0,n-1,1)
	{
		cin>>s>>t;
		auto it=M.find(s);
		if(it==M.end())M[s]=++cc;
		it=M.find(t);
		if(it==M.end())M[t]=++cc;
		p[i].X=M[s];
		p[i].Y=M[t];
	}
	int pre=-1;
	fup(i,0,n-1,1)
	{
		int x,y;
		tie(x,y)=p[i];
		if(x==pre)A[min(x,y)][max(x,y)]+=b;
		else A[min(x,y)][max(x,y)]+=a;
		pre=y;
	}
	priority_queue<int> q;
	fup(i,1,cc,1)fup(j,i+1,cc,1)if(A[i][j]>0)q.push(A[i][j]);
	int ans=0;
	while(!q.empty() && k>0 && q.top()>f)
	{
		ans+=f;
		q.pop();
		k--;
	}
	while(!q.empty())
	{
		ans+=q.top();
		q.pop();
	}
	cout<<ans;
}