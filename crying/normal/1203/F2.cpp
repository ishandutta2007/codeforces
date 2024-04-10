#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=110,MAXM=6e4+10,INF=1e9;
int n,r,f[MAXN][MAXM];
struct Node{
	int a,b,t;
	bool operator<(const Node& n2)const{
		if(t!=n2.t)return t<n2.t;
		if(t==0)return a<n2.a;
		return a+b>n2.a+n2.b;
	}
}node[MAXN];
void dp(){
	rep(j,0,60000)f[0][j]=-INF;
	f[0][r]=0;
	rep(i,1,n){
		rep(j,0,60000){
			f[i][j]=f[i-1][j];
			if(j-node[i].b>=node[i].a && j-node[i].b>=0 && j-node[i].b<=60000){
				f[i][j]=max(f[i][j],1+f[i-1][j-node[i].b]);
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&r);
	rep(i,1,n){
		scanf("%d%d",&node[i].a,&node[i].b);
		if(node[i].b<0)node[i].t=1;
	}
	sort(node+1,node+1+n);
	dp();
	int ans=-INF;
	rep(j,0,60000)ans=max(ans,f[n][j]);
	printf("%d",ans); 
	return 0;
}