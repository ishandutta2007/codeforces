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
const ll MOD = 1000003;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[]={2,2,-2,-2,1,1,-1,-1},ddy[]={1,-1,1,-1,2,-2,2,-2};

int a[50][50];
int n;
void ask(int x1,int y1,int x2,int y2)
{
	cout<<"? "<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<endl;
}
void dfs(int x1,int y1,int x2,int y2,int d,int c)
{
	if(x2>n || y2>n)return;
	c^=a[x2][y2];
	if(d==3)
	{
		if(c==0)
		{
			ask(x1,y1,x2,y2);
			int x;
			cin>>x;
			if((x1+y1)%2==0)
			{
				int fr=a[x2][y2],to=x?a[x1][y1]:1-a[x1][y1];
				fup(i,1,n,1)
					fup(j,1,n,1)
				{
					if(a[i][j]==fr)a[i][j]=to;
					else if(a[i][j]==5-fr)a[i][j]=1-to;
				}
			}
			else
			{
				int fr=a[x1][y1],to=x?a[x2][y2]:1-a[x2][y2];
				fup(i,1,n,1)
					fup(j,1,n,1)
				{
					if(a[i][j]==fr)a[i][j]=to;
					else if(a[i][j]==5-fr)a[i][j]=1-to;
				}
			}
			cout<<"!"<<endl;
			fup(i,1,n,1)
			{
				fup(j,1,n,1)cout<<a[i][j];
				cout<<endl;
			}
			exit(0);
		}
		return;
	}
	dfs(x1,y1,x2+1,y2,d+1,c);
	dfs(x1,y1,x2,y2+1,d+1,c);
}
int main(){
	SYNC;
	cin>>n;
	a[1][1]=1;a[1][2]=2;
	fup(i,1,n,1)
	{
		int t=i&1?1:2,x;
		if(t+2<=n)
		{
			ask(i,t,i,t+2);
			cin>>x;
			if(i==1 || i%2==0)a[i][t+2]=x?a[i][t]:1-a[i][t];
			else a[i][t]=x?a[i][t+2]:1-a[i][t+2];
		}
		if(i<n)
		{
			ask(i,t,i+1,t+1);
			cin>>x;
			a[i+1][t+1]=x?a[i][t]:1-a[i][t];
		}
		fup(j,t+4,n,2)
		{
			ask(i,j-2,i,j);
			cin>>x;
			a[i][j]=x?a[i][j-2]:1-a[i][j-2];
		}
	}
	fup(i,1,n,1)
	{
		int t=i&1?2:1,x;
		if(t+2<=n)
		{
			ask(i,t,i,t+2);
			cin>>x;
			if(i&1)a[i][t+2]=x?a[i][t]:5-a[i][t];
			else a[i][t]=x?a[i][t+2]:5-a[i][t+2];
		}
		if(i<n)
		{
			ask(i,t,i+1,t+1);
			cin>>x;
			a[i+1][t+1]=x?a[i][t]:5-a[i][t];
		}
		fup(j,t+4,n,2)
		{
			ask(i,j-2,i,j);
			cin>>x;
			a[i][j]=x?a[i][j-2]:5-a[i][j-2];
		}
	}
	fup(i,1,n,1)fup(j,1,n,1)dfs(i,j,i,j,0,0);
}