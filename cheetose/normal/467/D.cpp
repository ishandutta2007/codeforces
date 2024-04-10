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

Vi v[300001];
map<string,int> M;
string a[100000],s[300001];
pair<string,string> p[100000];
int A[100000],cc;
Pi P[100000],t[300001];
bool chk[300001];
priority_queue<pair<Pi,int> > q;
int main() {
	SYNC;
	int n,m;
	cin>>n;
	fup(i,0,n-1,1)cin>>a[i];
	cin>>m;
	fup(i,0,m-1,1)cin>>p[i].X>>p[i].Y;
	fup(i,0,n-1,1)for(char &c:a[i])if(c<'a')c+=32;
	fup(i,0,m-1,1)
	{
		for(char &c:p[i].X)if(c<'a')c+=32;
		for(char &c:p[i].Y)if(c<'a')c+=32;
	}
	fup(i,0,n-1,1)
	{
		if(M.find(a[i])==M.end())M[a[i]]=++cc;
		A[i]=M[a[i]];
	}
	fup(i,0,m-1,1)
	{
		if(M.find(p[i].X)==M.end())M[p[i].X]=++cc;
		if(M.find(p[i].Y)==M.end())M[p[i].Y]=++cc;
		P[i].X=M[p[i].X],P[i].Y=M[p[i].Y];
		v[P[i].Y].pb(P[i].X);
	}
	for(auto it=M.begin();it!=M.end();it++)
		s[it->Y]=it->X;
	fup(i,1,cc,1)
	{
		t[i].X=-count(ALL(s[i]),'r');
		t[i].Y=-s[i].length();
		q.push(mp(t[i],i));
	}
	while(!q.empty())
	{
		int x=q.top().Y;
		q.pop();
		if(chk[x])continue;
		chk[x]=1;
		for(int next:v[x])
		{
			if(t[next]<t[x])
			{
				t[next]=t[x];
				q.push(mp(t[next],next));
			}
		}
	}
	Pll ans=mp(0,0);
	fup(i,0,n-1,1)ans.X-=t[A[i]].X,ans.Y-=t[A[i]].Y;
	cout<<ans.X<<' '<<ans.Y;
}