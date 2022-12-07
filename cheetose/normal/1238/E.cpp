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

int cnt[22][22];
char s[100005];
int d[1<<20];
bool chk[1<<20];
int main(){
	fill(d,d+(1<<20),INF);
	int n,m;
	scanf("%d%d%s",&n,&m,s);
	fup(i,1,n-1,1)
	{
		char x=s[i-1],y=s[i];
		if(x!=y)
		{
			if(x>y)swap(x,y);
			cnt[x-'a'][y-'a']++;
		}
	}
	queue<int> q;
	chk[0]=1;
	q.push(0);
	d[0]=0;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		int t=bitset<22>(x).count()+1;
		fup(i,0,m-1,1)
		{
			if(~x&(1<<i))
			{
				int tt=0;
				fup(j,0,m-1,1)
				{
					if(x&(1<<j))tt+=t*cnt[min(i,j)][max(i,j)];
					else tt-=t*cnt[min(i,j)][max(i,j)];
				}
				d[x|(1<<i)]=min(d[x|(1<<i)],d[x]+tt);
				if(!chk[x|(1<<i)])
				{
					chk[x|(1<<i)]=1;
					q.push(x|(1<<i));
				}
			}
		}
	}
	printf("%d",d[(1<<m)-1]);
}