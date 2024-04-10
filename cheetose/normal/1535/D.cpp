#include <bits/stdc++.h>
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
#define MEM0(a) memset((a),0,sizeof(a))
#define MEM_1(a) memset((a),-1,sizeof(a))
#define ALL(a) a.begin(),a.end()
#define COMPRESS(a) sort(ALL(a));a.resize(unique(ALL(a))-a.begin())
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
const int MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

char s[(1<<18)+5];
int p[1<<18];
Vi v[1<<18];
int tree[1<<18];
int main(){
	int k;
	scanf("%d",&k);
	int n=(1<<k)-1,t=(n+1)/2;
	scanf("%s",s+1);
	int c=t+1;
	fup(i,1,n-1,2){
		p[i]=p[i+1]=c;
		v[c].pb(i);v[c].pb(i+1);
		c++;
	}
	fup(i,1,n,1){
		if(i<=t){
			if(s[i]=='?')tree[i]=2;
			else tree[i]=1;
		}else{
			if(s[i]=='?')tree[i]=tree[v[i][0]]+tree[v[i][1]];
			else if(s[i]=='0')tree[i]=tree[v[i][0]];
			else tree[i]=tree[v[i][1]];
		}
	}
	int q;
	scanf("%d",&q);
	while(q--){
		int i;
		char c;
		scanf("%d %c",&i,&c);
		s[i]=c;
		while(i){
			if(i<=t){
				if(s[i]=='?')tree[i]=2;
				else tree[i]=1;
			}else{
				if(s[i]=='?')tree[i]=tree[v[i][0]]+tree[v[i][1]];
				else if(s[i]=='0')tree[i]=tree[v[i][0]];
				else tree[i]=tree[v[i][1]];
			}
			i=p[i];
		}
		printf("%d\n",tree[n]);
	}
}