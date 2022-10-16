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
const int MAXN=3e5+10,MAXM=1e6+10,LIM=1e6+1;
int n,q,a[MAXN],s[MAXN],t[MAXN];
int tag[MAXM],prime[MAXN],minn[MAXM],tot;
int d[MAXN][10],fa[MAXM];
map<pi,int>e;
vector<int>bucket[MAXM];
int Find(int x){
	if(fa[x]==x)return x;
	return fa[x]=Find(fa[x]);
}
void Merge(int x,int y){
	if(Find(x)==Find(y))return;
	fa[Find(y)]=Find(x);
} 
void solve(){
	rep(i,1,LIM)minn[i]=1;
	rep(i,2,LIM){
		if(!tag[i])prime[++tot]=i,minn[i]=i;
		if(tot>3e5)break;
		rep(j,1,tot){
			if(prime[j]*i>LIM)break;
			tag[prime[j]*i]=1;
			minn[prime[j]*i]=prime[j];
			if(i%prime[j]==0)break;
		}
	}
}
void pre(){
	rep(i,1,n)fa[i]=i;
	rep(i,1,n){
		int num=a[i];
		while(num!=1){
			int j=minn[num];
			d[i][++d[i][0]]=j;
			bucket[j].pb(i);
			while(num%j==0)num/=j;
		}
	}
	rep(i,1,LIM+1){
		int sz=bucket[i].size();if(!sz)continue;
		int fr=bucket[i][0];
		rep(j,1,sz-1){
			Merge(fr,bucket[i][j]);
		}
	}
	memset(d,0,sizeof d);
	rep(i,1,n){
		int num=a[i]+1;
		while(num!=1){
			int j=minn[num];
			d[i][++d[i][0]]=j;
			while(num%j==0)num/=j;
		}
	//	printf("num:%d\n",a[i]+1);
		rep(j,1,d[i][0]){
			int u=d[i][j];if(bucket[u].size()==0)continue;
			int a=bucket[u][0];
			e[mp(Find(a),Find(i))]=e[mp(Find(i),Find(a))]=1;
		//	printf("a:%d(%d)\n",a,u);
			rep(k,j+1,d[i][0]){
				int v=d[i][k];if(bucket[v].size()==0)continue;
				int b=bucket[v][0];
				e[mp(Find(a),Find(b))]=e[mp(Find(b),Find(a))]=1;
			}
		}
	}
}
void solve(int x,int y){
	if(Find(x)==Find(y)){printf("0\n");return;}
	if(e[mp(Find(x),Find(y))]==1){printf("1\n");return;}
	printf("2\n");
}
int main(){
	solve();
	scanf("%d%d",&n,&q);
	rep(i,1,n){scanf("%d",&a[i]);}
	rep(i,1,q){scanf("%d%d",&s[i],&t[i]);}
	pre();
	rep(i,1,q){
		solve(s[i],t[i]);
	}
	return 0;
}