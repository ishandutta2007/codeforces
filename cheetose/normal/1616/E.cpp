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
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

char s[100005],t[100005];
struct FenwickTree{
	int n;
	Vi tree;
	
	FenwickTree(){}
	FenwickTree(int N){
		n=N;
		tree.resize(N+1);
	}
	
	void upd(int i, int k){
		while (i <= n){
			tree[i] += k;
			i += (i&-i);
		}
	}
	int sum(int i){
		int c = 0;
		while (i > 0){
			c += tree[i];
			i -= (i&-i);
		}
		return c;
	}
};
void solve(){
	int n;
	scanf("%d%s%s",&n,s+1,t+1);
	ll ans=INF,tmp=0;
	queue<int> q[26];
	auto T=FenwickTree(n);
	fup(i,1,n,1){
		q[s[i]-'a'].push(i);
	}
	fup(i,1,n,1){
		fup(c,0,t[i]-'a'-1,1){
			if(!q[c].empty()){
				ans=min(ans,tmp+q[c].front()-1-T.sum(q[c].front()));
			}
		}
		int c=t[i]-'a';
		if(q[c].empty())break;
		tmp+=q[c].front()-1-T.sum(q[c].front());
		T.upd(q[c].front(),1);
		q[c].pop();
	}
	if(ans==INF)ans=-1;
	printf("%lld\n",ans);
}
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}