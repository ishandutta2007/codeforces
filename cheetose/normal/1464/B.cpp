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
typedef pair<db, db> Pd;
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
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM=MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[]={2,2,-2,-2,1,1,-1,-1},ddy[]={1,-1,1,-1,2,-2,2,-2};

struct FenwickTree{
	int n;
	Vi tree;
	
	FenwickTree(){}
	FenwickTree(int N){
		n=N;
		tree.resize(N+1);
	}
	
	void upd(int i, int k)
	{
		while (i <= n)
		{
			tree[i] += k;
			i += (i&-i);
		}
	}
	int sum(int i)
	{
		int c = 0;
		while (i > 0)
		{
			c += tree[i];
			i -= (i&-i);
		}
		return c;
	}
	int sum(int l,int r){
		return sum(r)-sum(l-1);
	}
};
char s[111111],t[111111];
ll x,y;
int main(){
	scanf("%s",s+1);
	scanf("%lld%lld",&x,&y);
	ll ans=INF;
	int n=strlen(s+1);
	fup(KKK,0,1,1){
		FenwickTree Z(n),O(n);
		fup(i,1,n,1){
			if(s[i]=='?')t[i]='0';
			else t[i]=s[i];
		}
		ll res=0,c0=0,c1=0;
		fup(i,1,n,1){
			if(t[i]=='0'){
				res+=y*c1;
				c0++;
				Z.upd(i,1);
			}else{
				res+=x*c0;
				c1++;
				O.upd(i,1);
			}
		}
		ans=min(ans,res);
		fdn(i,n,1,1){
			if(s[i]=='?'){
				res-=O.sum(1,i-1)*y+O.sum(i+1,n)*x;
				Z.upd(i,-1);O.upd(i,1);
				res+=Z.sum(1,i-1)*x+Z.sum(i+1,n)*y;
				t[i]='1';
				ans=min(ans,res);
			}
		}
		reverse(s+1,s+n+1);
		swap(x,y);
	}
	printf("%lld\n",ans);
	
}