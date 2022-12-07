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
typedef pair<double, double> Pd;
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
const ll MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

int a[100000];
Vi v1,v2;
void print1()
{
	for(auto x:v1)printf("%d",x);
	exit(0);
}
void print2()
{
	for(auto x:v2)printf("%d",x);
	exit(0);
}
int main() {
	int n;
	scanf("%d",&n);
	fup(i,0,n-1,1)scanf("%1d",a+i);
	int t1=-1,t2=-1;
	fdn(t,n/2,1,1)
	{
		if(a[t]!=0)
		{
			t1=t;
			break;
		}
	}
	fup(t,n/2+1,n-1,1)
	{
		if(a[t]!=0)
		{
			t2=t;
			break;
		}
	}
	if(t1!=-1)
	{
		v1.resize(n-t1);
		fup(i,t1,n-1,1)v1[i-t1]+=a[i];
		int dif=n-2*t1;
		fup(i,0,t1-1,1)v1[i+dif]+=a[i];
		fdn(i,n-t1-1,1,1)
		{
			if(v1[i]>=10)
			{
				v1[i]-=10;
				v1[i-1]++;
			}
		}
		if(v1[0]>=10)
		{
			v1[0]-=10;
			v1.pb(0);
			fdn(i,n-t1,1,1)v1[i]=v1[i-1];
			v1[0]=1;
		}
	}
	if(t2!=-1)
	{
		v2.resize(t2);
		fup(i,0,t2-1,1)v2[i]+=a[i];
		int dif=n-t2;
		fup(i,t2,n-1,1)v2[i-dif]+=a[i];
		fdn(i,t2-1,1,1)
		{
			if(v2[i]>=10)
			{
				v2[i]-=10;
				v2[i-1]++;
			}
		}
		if(v2[0]>=10)
		{
			v2[0]-=10;
			v2.pb(0);
			fdn(i,t2,1,1)v2[i]=v2[i-1];
			v2[0]=1;
		}
	}
	if(v1.empty())print2();
	if(v2.empty())print1();
	int s1=v1.size(),s2=v2.size();
	if(s1<s2)print1();
	if(s2<s1)print2();
	fup(i,0,s1-1,1)
	{
		if(v1[i]<v2[i])print1();
		if(v1[i]>v2[i])print2();
	}
	print1();
}