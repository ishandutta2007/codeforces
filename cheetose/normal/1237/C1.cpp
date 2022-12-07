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
#define INF 987654321
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
const ll MOD = 16769023;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[]={2,2,-2,-2,1,1,-1,-1},ddy[]={1,-1,1,-1,2,-2,2,-2};

int x[50000],y[50000],z[50000];
int n;
void re(int a[])
{
	Vi vv;
	fup(i,0,n-1,1)vv.pb(a[i]);
	sort(ALL(vv));vv.resize(unique(ALL(vv))-vv.begin());
	fup(i,0,n-1,1)a[i]=lower_bound(ALL(vv),a[i])-vv.begin();
}
Vi v[50000];
bool chk[50000];
int main(){
	scanf("%d",&n);
	fup(i,0,n-1,1)scanf("%d%d%d",x+i,y+i,z+i);
	re(x);re(y);re(z);
	fup(i,0,n-1,1)v[z[i]].pb(i);
	Vi t;
	fup(i,0,n-1,1)
	{
		sort(ALL(v[i]),[&](int a,int b){
			if(x[a]!=x[b])return x[a]<x[b];
			return y[a]<y[b];
		});
		int N=v[i].size();
		fup(j,0,N-2,1)
		{
			if(x[v[i][j]]==x[v[i][j+1]])
			{
				chk[v[i][j]]=chk[v[i][j+1]]=1;
				printf("%d %d\n",v[i][j]+1,v[i][j+1]+1);
				j++;
			}
		}
		int tmp=-1;
		fup(j,0,N-1,1)
		{
			if(chk[v[i][j]])continue;
			if(tmp==-1)tmp=v[i][j];
			else
			{
				chk[tmp]=chk[v[i][j]]=1;
				printf("%d %d\n",tmp+1,v[i][j]+1);
				tmp=-1;
			}
		}
		if(~tmp)t.pb(tmp);
	}
	sort(ALL(t),[&](int a,int b){
		return z[a]<z[b];
	});
	int N=t.size();
	fup(i,1,N-1,2)printf("%d %d\n",t[i-1]+1,t[i]+1);
}