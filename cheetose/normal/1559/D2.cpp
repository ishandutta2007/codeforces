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

int n,m1,m2;
struct UF{
	int p[100005];
	void init(int n){
		iota(p,p+n+1,0);
	}
	int f(int x){
		return x==p[x]?x:p[x]=f(p[x]);
	}
	void merge(int x,int y){
		p[f(x)]=f(y);
	}
}R,C;
map<int,int> M[100005];
set<int> row[100005],col[100005];
set<Pi> S;
void merger(int x,int y){
	for(auto it=row[y].begin();it!=row[y].end();it++){
		M[x][*it]=M[y][*it];
		M[y].erase(*it);
		row[x].insert(*it);
		col[*it].insert(x);
		col[*it].erase(y);
	}
}
void mergec(int x,int y){
	for(auto it=col[y].begin();it!=col[y].end();it++){
		M[*it][x]=M[*it][y];
		M[*it].erase(y);
		col[x].insert(*it);
		row[*it].insert(x);
		row[*it].erase(y);
	}
}
int main(){
	scanf("%d%d%d",&n,&m1,&m2);
	R.init(n);C.init(n);
	fup(i,1,m1,1){
		int x,y;
		scanf("%d%d",&x,&y);
		R.merge(x,y);
	}
	fup(i,1,m2,1){
		int x,y;
		scanf("%d%d",&x,&y);
		C.merge(x,y);
	}
	if(m1<m2){
		swap(R,C);
		swap(m1,m2);
	}
	fup(i,1,n,1){
		int a=R.f(i),b=C.f(i);
		M[a][b]=i;
		row[a].insert(b);
		col[b].insert(a);
	}
	fup(i,1,n,1){
		if(R.f(i)==i){
			S.insert(mp(-row[i].size(),i));
		}
	}
	VPi ans;
	while(S.size()>1){
		int x=S.begin()->Y;
		S.erase(S.begin());
		int y=S.begin()->Y;
		S.erase(S.begin());
		auto it=row[x].begin();
		int a=*it;
		int b=*row[y].begin();
		if(a==b){
			it++;
			a=*it;
		}
		ans.pb(mp(M[x][a],M[y][b]));
		if(col[a].size()<col[b].size())swap(a,b);
		merger(x,y);
		mergec(a,b);
		S.insert(mp(-row[x].size(),x));
	}
	printf("%d\n",ans.size());
	for(auto [x,y]:ans)printf("%d %d\n",x,y);
}