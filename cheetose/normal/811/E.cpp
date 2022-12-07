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

int n,m,q;
int a[10][100000];
int p[40];
int find(int x){
	return x==p[x]?x:p[x]=find(p[x]);
}
void merge(int x,int y){
	x=find(x),y=find(y);
	p[x]=y;
}
struct Node{
	int res;
	int S,E;
	int l[10],r[10];
	Node(){
		S=E=-1,res=0,MEM_1(l),MEM_1(r);
	}
	Node(int j){
		S=E=j;
		int t=-1;
		int pr=-1;
		fup(i,0,n-1,1){
			if(a[i][j]==pr) l[i]=r[i]=t;
			else l[i]=r[i]=++t;
			pr=a[i][j];
		}
		res=t+1;
	}
};
Node merge(Node &L,Node &R){
	Node N;
	N.res=L.res+R.res;
	N.S=L.S,N.E=R.E;
	iota(p,p+40,0);
	fup(i,0,n-1,1){
		int t1=find(L.r[i]),t2=find(R.l[i]+20);
		if(a[i][L.E]==a[i][R.S] && t1!=t2){
			merge(t1,t2);
			N.res--;
		}
	}
	Vi tmp(40,-1);
	int t=0;
	fup(i,0,n-1,1){
		int r=find(L.l[i]);
		if(tmp[r]==-1)tmp[r]=t++;
		N.l[i]=tmp[r];

		r=find(R.r[i]+20);
		if(tmp[r]==-1)tmp[r]=t++;
		N.r[i]=tmp[r];
	}
	return N;
}
Node tree[262144];
void init(int node, int S, int E){
	if (S == E){
		tree[node] = Node(S);
		return;
	}
	init(2 * node, S, (S + E) / 2);
	init(2 * node + 1, (S + E) / 2 + 1, E);
	tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
}
Node find(int node, int S, int E, int i, int j)
{
	if (i > E || j < S)return Node();
	if (i <= S && j >= E)return tree[node];
	Node L=find(node*2,S,(S+E)/2,i,j),R=find(node*2+1,(S+E)/2+1,E,i,j);
	if(L.S==-1)return R;
	if(R.S==-1)return L;
	return merge(L,R);
}
int main() {
	scanf("%d%d%d",&n,&m,&q);
	fup(i,0,n-1,1)fup(j,0,m-1,1)scanf("%d",&a[i][j]);
	init(1,0,m-1);
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		--x,--y;
		printf("%d\n",find(1,0,m-1,x,y).res);
	}
}