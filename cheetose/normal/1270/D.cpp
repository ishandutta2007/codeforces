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
typedef vector<ld> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef tuple<int, int, int> iii;
typedef tuple<int,int,int,int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const int MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[]={-1,-2,1,-2,2,-1,2,1},ddy[]={-2,-1,-2,1,-1,2,1,2};

int a[501];
int main(){
	MEM_1(a);
	SYNC;
	int n,k;
	cin>>n>>k;
	if(2*k<=n+1)
	{
		fup(i,1,k,1)
		{
			cout<<"? ";
			for(int c=0,j=1;c<k && j<=n;j++)
				if(a[j]==-1)
				{
					cout<<j<<' ';
					c++;
				}
			cout<<endl;
			int p,x;
			cin>>p>>x;
			a[p]=x;
		}
		cout<<"? ";
		Vi v;
		fup(i,1,n,1)
		{
			if(a[i]!=-1)
			{
				cout<<i<<' ';
				v.pb(a[i]);
			}
		}
		sort(ALL(v));
		cout<<endl;
		int p,x;
		cin>>p>>x;
		fup(i,0,k-1,1)if(v[i]==x)cout<<"! "<<i+1<<endl;
		return 0;
	}
	map<int,int> M;
	fup(i,1,k+1,1)
	{
		cout<<"? ";
		fup(j,1,k+1,1)
		{
			if(i!=j)cout<<j<<' ';
		}
		cout<<endl;
		int p,x;
		cin>>p>>x;
		M[x]++;
	}
	Vi v;
	for(auto it=M.begin();it!=M.end();it++)
	{
		v.pb(it->Y);
	}
	int t=v.back();
	cout<<"! "<<t<<endl;
}