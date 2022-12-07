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
#define INF 1987654321
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
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

void print(int x1,int y1,int x2,int y2,int Q)
{
	if(Q)cout<<"? ";
	else cout<<"! ";
	cout<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<endl;
}
int main() {
	SYNC;
	int n;
	cin>>n;
	int c=-1;
	fup(i,1,n,1)
	{
		int x;
		print(1,1,i,n,1);
		cin>>x;
		if(x&1)
		{
			c=i;
			break;
		}
	}
	Pi a1,a2;
	if(~c)
	{
		int l=1,r=n,x;
		while(l<=r)
		{
			int k=(l+r)>>1;
			print(c,1,c,k,1);
			cin>>x;
			if(x&1)r=k-1;
			else l=k+1;
		}
		a1=mp(c,l);
		
		fup(i,c+1,n,1)
		{
			print(c+1,1,i,n,1);
			cin>>x;
			if(x&1)
			{
				c=i;
				break;
			}
		}
		l=1,r=n;
		while(l<=r)
		{
			int k=(l+r)>>1;
			print(c,1,c,k,1);
			cin>>x;
			if(x&1)r=k-1;
			else l=k+1;
		}
		a2=mp(c,l);
		
		print(a1.X,a1.Y,a2.X,a2.Y,0);
		return 0;
	}
	else
	{
		int d=-1,x;
		fup(i,1,n,1)
		{
			print(1,1,n,i,1);
			cin>>x;
			if(x&1)
			{
				d=i;
				break;
			}
		}
		int l=1,r=n;
		while(l<=r)
		{
			int k=(l+r)>>1;
			print(1,d,k,d,1);
			cin>>x;
			if(x&1)r=k-1;
			else l=k+1;
		}
		a1=mp(l,d);
		fup(i,d+1,n,1)
		{
			print(l,i,l,i,1);
			cin>>x;
			if(x&1)
			{
				d=i;
				break;
			}
		}
		a2=mp(l,d);
		print(a1.X,a1.Y,a2.X,a2.Y,0);
		return 0;
	}
}