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

map<iii,int> M;
iii a[55000];
int c;
int A[3],d[55000],parent[55000];
char s[70][71];
int QQ(int x,int y,int z)
{
	if(x>y)swap(x,y);
	if(y>z)swap(y,z);
	if(x>y)swap(x,y);
	return M[iii(x,y,z)];
}
int main() {
	MEM_1(d);
	MEM_1(parent);
	int n;
	scanf("%d",&n);
	fup(i,0,n-1,1)
		fup(j,i+1,n-1,1)
		fup(k,j+1,n-1,1)
	{
		iii I=iii(i,j,k);
		M[I]=c;
		a[c++]=I;
	}
	fup(i,0,2,1)
	{
		scanf("%d",A+i);
		A[i]--;
	}
	sort(A,A+3);
	fup(i,0,n-1,1)scanf("%s",s[i]);
	int S=M[iii(A[0],A[1],A[2])];
	d[S]=0;
	queue<int> q;
	q.push(S);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		iii I=a[x];
		int xx,yy,zz;
		tie(xx,yy,zz)=I;
		fup(i,0,n-1,1)
		{
			if(i==xx || i==yy || i==zz)continue;
			if(s[i][xx]==s[yy][zz])
			{
				int T=QQ(i,yy,zz);
				if(d[T]==-1)
				{
					d[T]=d[x]+1;
					parent[T]=x;
					q.push(T);
				}
			}
			if(s[i][yy]==s[xx][zz])
			{
				int T=QQ(i,xx,zz);
				if(d[T]==-1)
				{
					d[T]=d[x]+1;
					parent[T]=x;
					q.push(T);
				}
			}
			if(s[i][zz]==s[yy][xx])
			{
				int T=QQ(i,yy,xx);
				if(d[T]==-1)
				{
					d[T]=d[x]+1;
					parent[T]=x;
					q.push(T);
				}
			}
		}
	}
	if(d[0]==-1)return !printf("-1");
	printf("%d\n",d[0]);
	stack<Pi> st;
	int now=0;
	while(now!=S)
	{
		int pr=parent[now];
		int g[3],h[3];
		tie(g[0],g[1],g[2])=a[now];
		tie(h[0],h[1],h[2])=a[pr];
		bool chk[2][3]={0};
		fup(i,0,2,1)
			fup(j,0,2,1)
		{
			if(g[i]==h[j])
			{
				chk[0][i]=chk[1][j]=1;
			}
		}
		int t1,t2;
		fup(i,0,2,1)
		{
			if(!chk[0][i])t1=g[i];
			if(!chk[1][i])t2=h[i];
		}
		st.push(mp(t2,t1));
		now=pr;
	}
	while(!st.empty())
	{
		printf("%d %d\n",st.top().X+1,st.top().Y+1);
		st.pop();
	}
}