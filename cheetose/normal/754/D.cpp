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

multiset<int,greater<int> > S;
priority_queue<iii,Viii,greater<iii> > q;
set<int> now;
struct A{
	int S,E,i;
}a[300001];
int main() {
	int n,k,res=0;
	scanf("%d%d",&n,&k);
	fup(i,1,n,1)
	{
		scanf("%d%d",&a[i].S,&a[i].E);
		a[i].i=i;
	}
	sort(a+1,a+n+1,[&](A a1,A a2){return a1.S<a2.S;});
	int ans;
	fup(i,1,k-1,1)
	{
		S.insert(a[i].S);
		q.push(iii(a[i].E,a[i].S,a[i].i));
		now.insert(a[i].i);
	}
	fup(i,k,n,1)
	{
		S.insert(a[i].S);
		q.push(iii(a[i].E,a[i].S,a[i].i));
		now.insert(a[i].i);
		int R=get<0>(q.top()),L=*S.begin();
		if(R-L+1>res)
		{
			res=R-L+1;
			ans=i;
		}
		int t,tt;
		tie(ignore,t,tt)=q.top();
		q.pop();
		S.erase(S.find(t));
		now.erase(now.find(tt));
	}
	printf("%d\n",res);
	if(res==0)fup(i,1,k,1)printf("%d ",i);
	else
	{
		S.clear();
		while(!q.empty())q.pop();
		now.clear();
		fup(i,1,k-1,1)
		{
			S.insert(a[i].S);
			q.push(iii(a[i].E,a[i].S,a[i].i));
			now.insert(a[i].i);
		}
		fup(i,k,ans,1)
		{
			S.insert(a[i].S);
			q.push(iii(a[i].E,a[i].S,a[i].i));
			now.insert(a[i].i);
			if(i==ans)break;
			int t,tt;
			tie(ignore,t,tt)=q.top();
			q.pop();
			S.erase(S.find(t));
			now.erase(now.find(tt));
		}
		for(int x:now)printf("%d ",x);
	}
}