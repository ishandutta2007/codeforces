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
#define INF (1e18+5)
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

double prob(int L,int R,int l,int r)
{
	if(l>R || r<L)return 0;
	l=max(l,L),r=min(r,R);
	return 1.0*(r-l+1)/(R-L+1);
}
int L[6],R[6];
int main() {
	int n;
	scanf("%d",&n);
	fup(i,1,n,1)scanf("%d%d",L+i,R+i);
	double ans=0;
	fup(f,1,n,1)fup(s,1,n,1)
	{
		if(f==s)continue;
		fup(k,L[s],R[s],1)
		{
			double p=1;
			fup(i,1,n,1)
			{
				if(i==s)continue;
				if(i==f)
				{
					if(i<s)p*=prob(L[i],R[i],k,10000);
					else p*=prob(L[i],R[i],k+1,10000);
				}
				else
				{
					if(i<s)p*=prob(L[i],R[i],1,k-1);
					else p*=prob(L[i],R[i],1,k);
				}
			}
			ans+=p*k/(R[s]-L[s]+1);
		}
	}
	printf("%.12f",ans);
}