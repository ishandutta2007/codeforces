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
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const ll MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

int a[100001];
int cnt[100001],c[100001];
set<int> S;
int main() {
	int n;
	scanf("%d",&n);
	c[0]=100000;
	int ans=0;
	fup(i,1,n,1)
	{
		int x;
		scanf("%d",&x);
		c[cnt[x]]--;
		if(c[cnt[x]]==0)S.erase(cnt[x]);
		cnt[x]++;
		c[cnt[x]]++;
		if(c[cnt[x]]==1)S.insert(cnt[x]);
		if(S.size()==1)
		{
			if(*S.begin()==1 || c[*S.begin()]==1)ans=max(ans,i);
		}
		else if(S.size()==2)
		{
			auto it=S.begin();
			auto it2=it;
			it2++;
			int t1=*it,t2=*it2;
			fup(ii,0,1,1)
			{
				if(c[t2]==1)
				{
					if(t2==1 || t1+1==t2)ans=max(ans,i);
				}
				swap(t1,t2);
			}
		}
	}
	printf("%d",ans);
}