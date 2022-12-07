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

int L[8002];
char s[8002];
int pi[8002][8002],d[8002];
int main() {
	L[1]=1,L[10]=2,L[100]=3,L[1000]=4;
	fup(i,1,8000,1)
		if(!L[i])L[i]=L[i-1];
	scanf("%s",s);
	int n = strlen(s);
	fup(k,0,n-1,1)
	{
		pi[k][k]=k;
		for(int i=k+1,j=k;i<n;i++)
		{
			pi[k][i]=k;
			while(j>k && s[i]!=s[j])j=pi[k][j-1];
			if(s[i]==s[j])pi[k][i]=++j;
		}
	}
	fup(i,0,n-1,1)
	{
		d[i]=INF;
		fup(j,0,i,1)
		{
			int l=i-j+1,t;
			int p=pi[j][i]-j;
			if(l%(l-p)==0)t=l-p+L[l/(l-p)];
			else t=l+1;
			d[i]=min(d[i],(j>0?d[j-1]:0) + t);
		}
	}
	printf("%d",d[n-1]);
}