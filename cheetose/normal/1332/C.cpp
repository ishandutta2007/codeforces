#include <bits/stdc++.h>
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

char s[200002];
int cnt[200002][26],chk[200002];
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		scanf("%s",s);
		fup(i,0,n-1,1)chk[i]=-1;
		int cc=0;
		fup(i,0,n-1,1)
		{
			if(chk[i]==-1)
			{
				queue<int> q;
				chk[i]=cc;
				q.push(i);
				while(!q.empty())
				{
					int x=q.front();
					q.pop();
					if(x+k<n && chk[x+k]==-1)
					{
						chk[x+k]=cc;
						q.push(x+k);
					}
					if(x-k>=0 && chk[x-k]==-1)
					{
						chk[x-k]=cc;
						q.push(x-k);
					}
					if(chk[n-1-x]==-1)
					{
						chk[n-x-1]=cc;
						q.push(n-1-x);
					}
				}
				cc++;
			}
		}
		fup(i,0,cc-1,1)fup(j,0,25,1)cnt[i][j]=0;
		fup(i,0,n-1,1)cnt[chk[i]][s[i]-'a']++;
		int ans=0;
		fup(i,0,cc-1,1)
		{
			int sum=0,mx=0;
			fup(j,0,25,1)
			{
				mx=max(mx,cnt[i][j]);
				sum+=cnt[i][j];
			}
			ans+=sum-mx;
		}
		printf("%d\n",ans);
	}
}