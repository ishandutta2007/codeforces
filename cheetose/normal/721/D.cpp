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
const ll MOD = 1000000009;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

ll a[200000];
ll ans[200000];
int main() {
	int n,k,x;
	scanf("%d%d%d",&n,&k,&x);
	int cnt=0;
	priority_queue<LLL,VLLL,greater<LLL> > q;
	fup(i,0,n-1,1)scanf("%lld",a+i);
	fup(i,0,n-1,1)
	{
		if(a[i]<0)
		{
			cnt++;
			q.push(LLL(-a[i],-1,i));
		}
		else q.push(LLL(a[i],1,i));
	}	
	if(cnt%2==0)
	{
		LLL t=q.top();
		ll xx,yy,ii;
		tie(xx,yy,ii)=t;
		q.pop();
		while(k>0 && xx>=0)k--,xx-=x;
		if(xx>=0)q.push(LLL(xx,yy,ii));
		else q.push(LLL(-xx,-yy,ii));
	}
	while(k--)
	{
		LLL t=q.top();
		ll xx,yy,ii;
		tie(xx,yy,ii)=t;
		q.pop();
		xx+=x;
		q.push(LLL(xx,yy,ii));
	}
	while(!q.empty())
	{
		LLL t=q.top();
		ll xx,yy,ii;
		tie(xx,yy,ii)=t;
		q.pop();
		ans[ii]=xx*yy;
	}
	fup(i,0,n-1,1)printf("%lld ",ans[i]);
}