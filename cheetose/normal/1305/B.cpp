#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define y0 y12
#define y1 y22
#define INF 2000000005
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
typedef tuple<int, int, int, int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

char s[1005];
bool chk[1005];
int cnt[1005];
int main() {
	Vi ans1;
	vector<Vi> ans2;
	scanf("%s",s+1);
	int n=strlen(s+1);
	while(1)
	{
		bool ok=0;
		fdn(i,n,1,1)
		{
			cnt[i]=cnt[i+1];
			if(chk[i])continue;
			if(s[i]==')')cnt[i]++;
		}
		Vi v;
		fup(i,1,n,1)
		{
			if(chk[i])continue;
			if(s[i]=='(' && cnt[i]>=(v.size()+1))
			{
				ok=1;
				v.pb(i);
			}
		}
		if(!ok)break;
		int t=v.size();
		fdn(i,n,1,1)
		{
			if(chk[i])continue;
			if(s[i]==')' && v.size()<2*t)v.pb(i);
		}
		sort(ALL(v));
		for(int x:v)chk[x]=1;
		ans1.pb(t*2);ans2.pb(v);
	}
	printf("%d\n",ans1.size());
	int N=ans1.size();
	fup(i,0,N-1,1)
	{
		printf("%d\n",ans1[i]);
		for(int x:ans2[i])printf("%d ",x);
			puts("");
	}
}