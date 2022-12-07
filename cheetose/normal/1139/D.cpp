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
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

ll inv[100001];
bool primechk[100001];
int mu[100001];
void get_mu()
{
    int i, j;
    for(i=1 ; i<=100000 ; i++)
    {
        mu[i]=1;
        primechk[i]=1;
    }
    primechk[1]=0;
    for(i=2 ; i<=100000 ; i++)
    {
        if(primechk[i]==1)
        {
            mu[i]=-mu[i];
            for(j=2 ; i*j<=100000 ; j++)
            {
                primechk[i*j]=0;
                if(j%i==0)
                {
                    mu[i*j]=0;  
                }   
                else
                {
                    mu[i*j]=-mu[i*j];
                }
            }   
        }   
    }
	fup(i,1,100000,1)mu[i]*=-1;
}
int main() {
	fup(i,1,100000,1)inv[i]=POW(i,MOD-2);
	get_mu();
	int m;
	scanf("%d",&m);
	ll ans=inv[m];
	fup(i,2,m,1)
	{
		ll a=m/i,b=m-a;
		ll t=(b*inv[m])%MOD;
		t=(t*a*(2*m-a))%MOD;
		t=(t*inv[m-a])%MOD;
		t=(t*inv[m-a])%MOD;
		ans=(ans+mu[i]*t)%MOD;
		if(ans<0)ans+=MOD;
	}
	printf("%lld",ans);
}