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

Vi v[200001];
struct cmp{
	 bool operator() (int a,int b){
		 return v[a].back()>v[b].back();
    }
};
set<int,cmp> S;
int main() {
	int n;
	scanf("%d",&n);
	fup(i,1,n,1)v[i].pb(0);
	fup(i,1,n,1)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].pb(b);
	}
	fup(i,1,n,1)S.insert(i);
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int k;
		scanf("%d",&k);
		Vi vv;
		fup(i,0,k-1,1)
		{
			int x;
			scanf("%d",&x);
			auto it=S.find(x);
			if(it!=S.end())S.erase(it);
			vv.pb(x);
		}
		if(S.empty() || v[*S.begin()].back()==0)puts("0 0");
		else
		{
			int c=*S.begin();
			printf("%d ",c);
			auto it=S.begin();
			it++;
			if(it==S.end() || v[*it].back()==0)printf("%d\n",v[c][1]);
			else
			{
				int rr=v[*it].back();
				int l=1,r=v[c].size()-1;
				while(l<=r)
				{
					int m=(l+r)>>1;
					if(v[c][m]>rr)r=m-1;
					else l=m+1;
				}
				printf("%d\n",v[c][l]);
			}
		}
		fup(i,0,k-1,1)S.insert(vv[i]);
	}
}