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
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

Vi v[101];
int a[101],b[101],ind[101],n;
Pi rev1[101],rev2[101];
int res(int x,int y)
{
	int c=0;
	if(rev1[x]<rev1[y])
	{
		if(rev2[x]<rev1[y])
		{
			if(rev2[x]>rev2[y])c++;
		}
		else
		{
			c++;
			if(rev2[x]<rev2[y])c++;
		}
	}
	else
	{
		if(rev2[x]>rev1[y])
		{
			if(rev2[x]<rev2[y])c++;
		}
		else
		{
			c++;
			if(rev2[x]>rev2[y])c++;
		}
	}
	return c;
}
Vi vv;
Pi cur[101];
int main() {
	scanf("%d",&n);
	fup(i,1,n,1)
	{
		scanf("%d%d",a+i,b+i);
		b[i]+=a[i];
		rev1[i]=mp(-a[i],i);
		rev2[i]=mp(-b[i],i);
	}
	fup(i,1,n,1)
		fup(j,i+1,n,1)
	{
		int t1=res(i,j),t2=res(j,i);
		if(t1>t2)v[i].pb(j),ind[j]++;
		else if(t1<t2)v[j].pb(i),ind[i]++;
	}
	queue<int> q;
	fup(i,1,n,1)if(!ind[i])q.push(i);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		vv.pb(x);
		for(int next:v[x])
		{
			ind[next]--;
			if(!ind[next])q.push(next);
		}
	}
	fup(i,1,n,1)cur[i]=rev1[i];
	sort(cur+1,cur+n+1);
	int ans=0;
	fup(ii,0,n-1,1)
	{
		int des=vv[ii];
		int t1,t2;
		fup(i,1,n,1)
		{
			if(cur[i].Y==des)
			{
				t1=i;
				cur[i]=rev2[des];
				break;
			}
		}
		sort(cur+1,cur+n+1);
		fup(i,1,n,1)
		{
			if(cur[i].Y==des)
			{
				t2=i;
				break;
			}
		}
		ans+=abs(t1-t2);
	} 
	printf("%d",ans);
}