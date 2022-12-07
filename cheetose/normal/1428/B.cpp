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
#define MEM0(a) memset((a),0,sizeof(a))
#define MEM_1(a) memset((a),-1,sizeof(a))
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
typedef vector<db> Vd;
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
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

Vi v[300003];
vector<Vi> SCC;
char s[300003];
int num[300003], low[300003], sn[300003];
bool chk[300003];
stack<int> st;
int cnt, SN;
void dfs(int n)
{
	chk[n] = 1;
	st.push(n);
	num[n] = ++cnt;
	low[n] = cnt;
	for (int next : v[n])
	{
		if (num[next] == 0)
		{
			dfs(next);
			low[n] = min(low[n], low[next]);
		}
		else if (chk[next])
			low[n] = min(low[n], num[next]);
	}
	if (num[n] == low[n])
	{
		Vi scc;
		while (!st.empty())
		{
			int x = st.top();
			st.pop();
			sn[x] = SN;
			chk[x] = 0;
			scc.push_back(x);
			if (n == x)
				break;
		}
		SCC.push_back(scc);
		SN++;
	}
}
int solve(){
	int n;
	scanf("%d%s",&n,s);
	SCC.clear();
	fup(i,0,n-1,1){
		v[i].clear();
		SN=0,cnt=0;
		num[i]=low[i]=sn[i]=0;
	}
	fup(i,0,n-1,1){
		if(s[i]=='-'){
			v[i].pb((i+1)%n);
			v[(i+1)%n].pb(i);
		}
		if(s[i]=='>')v[i].pb((i+1)%n);
		if(s[i]=='<')v[(i+1)%n].pb(i);
	}
	fup(i,0,n-1,1)if(!num[i])dfs(i);
	int ans=0;
	fup(i,0,SN-1,1){
		if(SCC[i].size()>1)ans+=SCC[i].size();
	}
	return ans;
}
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--)printf("%d\n",solve());
}