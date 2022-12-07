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
#define INF 987654321987654321
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
int ddx[]={2,2,-2,-2,1,1,-1,-1},ddy[]={1,-1,1,-1,2,-2,2,-2};

char s[200005],t[200005];
int n,k;
inline int pr(int x){return (x+n-1)%n;}
inline int ne(int x){return (x+1)%n;}
bool chk[200005];
int main(){
	memset(t,'.',sizeof(t));
	scanf("%d%d%s",&n,&k,s);
	t[n]=0;
	if(n%2==0)
	{
		bool ok=1;
		fup(i,0,n-1,1)if(s[i]==s[pr(i)])ok=0;
		if(ok)
		{
			if(k&1)
				fup(i,0,n-1,1)printf("%c",(char)(153-s[i]));
			else printf("%s",s);
			return 0;
		}
	}
	fup(i,0,n-1,1)if(s[i]==s[pr(i)])t[i]=s[i],t[pr(i)]=s[pr(i)];
	queue<iii> q;
	fup(i,0,n-1,1)
		if(t[i]=='.')
		{
			if(t[pr(i)]!='.')q.push(iii(i,1,0)),chk[i]=1;
			else if(t[ne(i)]!='.')q.push(iii(i,1,1)),chk[i]=1;
		}
	while(!q.empty())
	{
		int i,kk,cc;
		tie(i,kk,cc)=q.front();
		q.pop();
		if(cc==0)
		{
			char c=t[pr(i)];
			if(kk<=k)t[i]=c;
			else t[i]=(char)(153-c);
			if(t[ne(i)]=='.' && !chk[ne(i)])q.push(iii(ne(i),kk+1,0)),chk[ne(i)]=1;
		}
		else
		{
			char c=t[ne(i)];
			if(kk<=k)t[i]=c;
			else t[i]=(char)(153-c);
			if(t[pr(i)]=='.' && !chk[pr(i)])q.push(iii(pr(i),kk+1,1)),chk[pr(i)]=1;
		}
	}
	printf("%s\n",t);
}