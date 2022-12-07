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
const int MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

struct Node {
	int l[3],r[3],cnt;
};
Node tree[1<<20];
int a[3][500005];
int p[8];
int f(int x){
	return x==p[x]?x:p[x]=f(p[x]);
}
void merge(int x,int y,int &c){
	x=f(x),y=f(y);
	if(x==y)return;
	c--;
	p[x]=y;
}
Node merge(Node &L,Node &R){
	Node res;
	res.cnt=L.cnt+R.cnt;
	Vi vv;
	iota(p,p+8,0);
	int t[8],tc=0;
	MEM_1(t);
	fup(i,0,2,1){
		if(L.r[i]!=-1 && R.l[i]!=-1)merge(L.r[i],R.l[i]+4,res.cnt);
	}
	fup(i,0,2,1){
		if(L.l[i]==-1){
			res.l[i]=-1;
		}else{
			int z=f(L.l[i]);
			if(t[z]==-1){
				t[z]=tc++;
			}
			res.l[i]=t[z];
		}
	}
	fup(i,0,2,1){
		if(R.r[i]==-1){
			res.r[i]=-1;
		}else{
			int z=f(R.r[i]+4);
			if(t[z]==-1){
				t[z]=tc++;
			}
			res.r[i]=t[z];
		}
	}
	return res;
}
void init(int node,int S,int E){
	if(S==E){
		int c=0;
		fup(i,0,2,1){
			if(a[i][S])c|=(1<<i);
			tree[node].l[i]=tree[node].r[i]=a[i][S]-1;
		}
		if(c==5){
			tree[node].cnt=2;
			tree[node].l[2]=tree[node].r[2]=1;
		}
		else if(c!=0)tree[node].cnt=1;
		return;
	}
	int L=node<<1,R=L|1,M=S+E>>1;
	init(L,S,M);
	init(R,M+1,E);
	tree[node]=merge(tree[L],tree[R]);
}
Node find(int node,int S,int E,int i,int j){
	Node T;
	T.cnt=-1;
	if(i>E || j<S)return T;
	if (i<=S && j>=E)return tree[node];
	int l=node<<1,r=l|1,m=S+E>>1;
	Node L=find(l,S,m,i,j);
	Node R=find(r,m+1,E,i,j);
	if (L.cnt==-1)return R;
	if (R.cnt==-1)return L;
	return merge(L,R);
}
int main(){
	int n,q;
	scanf("%d",&n);
	fup(i,0,2,1)fup(j,1,n,1)scanf("%1d",a[i]+j);
	init(1,1,n);
	scanf("%d",&q);
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",find(1,1,n,x,y).cnt);
	}
}