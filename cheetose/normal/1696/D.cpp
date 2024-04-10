#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define eb emplace_back
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
typedef pair<db, db> Pd;
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

int a[250005],b[250005];
int tree[524288],mntree[524288],mxtree[524288];
void init(int node,int S,int E){
	if(S==E){
		tree[node]=b[S];
		mntree[node]=mxtree[node]=S;
		return;
	}
	int L=node<<1,R=L|1,M=S+E>>1;
	init(L,S,M);
	init(R,M+1,E);
	tree[node]=min(tree[L],tree[R]);
	mxtree[node]=a[mxtree[L]]>a[mxtree[R]]?mxtree[L]:mxtree[R];
	mntree[node]=a[mntree[L]]<a[mntree[R]]?mntree[L]:mntree[R];
}
void upd(int node,int S,int E,int k,int dif){
	if(S==E){
		tree[node]=dif;
		return;
	}
	int L=node<<1,R=L|1,M=S+E>>1;
	if(k<=M)upd(L,S,M,k,dif);
	else upd(R,M+1,E,k,dif);
	tree[node]=min(tree[L],tree[R]);
}
int find(int node,int S,int E,int i,int j){
	if(i>E || j<S)return INF;
	if(i<=S && j>=E)return tree[node];
	int L=node<<1,R=L|1,M=S+E>>1;
	return min(find(L,S,M,i,j),find(R,M+1,E,i,j));
}
int mnfind(int node,int S,int E,int i,int j){
	if(i>E || j<S)return -1;
	if(i<=S && j>=E)return mntree[node];
	int L=node<<1,R=L|1,M=S+E>>1;
	int t1=mnfind(L,S,M,i,j),t2=mnfind(R,M+1,E,i,j);
	if(t1==-1)return t2;
	if(t2==-1)return t1;
	return a[t1]<a[t2]?t1:t2;
}
int mxfind(int node,int S,int E,int i,int j){
	if(i>E || j<S)return -1;
	if(i<=S && j>=E)return mxtree[node];
	int L=node<<1,R=L|1,M=S+E>>1;
	int t1=mxfind(L,S,M,i,j),t2=mxfind(R,M+1,E,i,j);
	if(t1==-1)return t2;
	if(t2==-1)return t1;
	return a[t1]>a[t2]?t1:t2;
}
void solve(){
	int n;
	scanf("%d",&n);
	fup(i,1,n,1){
		scanf("%d",a+i);
		b[a[i]]=i;
	}
	init(1,1,n);
	int ans=0;
	for(int i=1;i<n;){
		ans++;
		int t,w;
		if(a[i]>a[i+1]){
			t=find(1,1,n,a[i]+1,n);
			if(t==INF)t=n+1;
			w=mnfind(1,1,n,i+1,t-1);
		}else{
			t=find(1,1,n,1,a[i]-1);
			if(t==INF)t=n+1;
			w=mxfind(1,1,n,i+1,t-1);
		}
		fup(j,i,w-1,1)upd(1,1,n,a[j],INF);
		i=w;
	}
	printf("%d\n",ans);
}
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}