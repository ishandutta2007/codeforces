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

typedef bitset<1000> BS;
BS bs[30];
Pi p[1<<15];
int n,s,s2,d;
unordered_map<BS,int> M;
void dfs(int N,const BS &b,int c){
	if(N==s2){
		auto it=M.find(b);
		if(it==M.end()){
			M[b]=c;
		}else{
			it->Y=min(it->Y,c);
		}
		return;
	}
	dfs(N+1,b,c);
	dfs(N+1,b^bs[N],c+1);
}
int dfs2(int N,const BS &b,int c){
	if(N==s){
		auto it=M.find(b);
		if(it==M.end()){
			return INF;
		}else{
			return it->Y+c;
		}
	}
	return min(dfs2(N+1,b,c),dfs2(N+1,b^bs[N],c+1));
}
int main(){
	scanf("%d%d%d",&n,&s,&d);
	fup(i,0,s-1,1){
		int c;
		scanf("%d",&c);
		while(c--){
			int x;
			scanf("%d",&x);
			bs[i][x-1]=1;
		}
	}
	s2=s*2/3;
	BS bb;
	dfs(0,bb,0);
	fup(i,0,d-1,1){
		BS b;
		int c;
		scanf("%d",&c);
		while(c--){
			int x;
			scanf("%d",&x);
			b[x-1]=1;
		}
		int res=dfs2(s2,b,0);
		if(res==INF)res=-1;
		printf("%d\n",res);
	}
}