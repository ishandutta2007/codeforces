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
const int MAXN=4e5+10,MAXM=(1<<8)+10,INF=1e9;
int n,m,k,L[MAXN],R[MAXN],b[MAXN],tot;
int len,cnt[MAXN],d[MAXN],sz[MAXN];
map<int,int>occ,c[MAXN];
int f[2][MAXM],g[MAXM],c2[MAXN][10],ans;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,n){
		scanf("%d%d",&L[i],&R[i]);
		b[++tot]=L[i];b[++tot]=R[i];
	}
	sort(b+1,b+1+tot);
	tot=unique(b+1,b+1+tot)-b-1;
	b[tot+1]=m+1;
	if(b[1]>1)cnt[++len]=b[1]-1;
	rep(i,1,tot){
		cnt[++len]=1;
		occ[b[i]]=len;
		if(b[i]+1!=b[i+1])cnt[++len]=b[i+1]-b[i]-1;
	}
	rep(i,1,n){
		int st=occ[L[i]],ed=occ[R[i]];
		rep(j,st,ed){
			c[j][i]=sz[j];
			c2[j][sz[j]]=i;
			sz[j]++;
		}	
	}
	rep(i,1,len){
		/*
		rep(j,0,sz[i]-1){
			printf("%d ",c2[i][j]);
		}
		printf("\n");
		*/
		rep(j,0,(1<<k)-1)f[i&1][j]=0;
		rep(j,0,(1<<sz[i])-1){
			int flag=0,state=0;
			rep(x,0,sz[i]-1){if(!(j>>x&1))continue;
				flag^=1;
				auto it=c[i-1].find(c2[i][x]);
				if(it==c[i-1].end())continue;
				state|=(1<<(it->se));
			}
			f[i&1][j]=g[state]+flag*cnt[i]; 
		//	printf("f[%d][%d]:%d\n",i,j,f[i&1][j]);
		}
		rep(j,0,(1<<sz[i])-1){
			g[j]=f[i&1][j];
		}
		rep(j,0,sz[i]-1){
			auto it=c[i+1].find(c2[i][j]);
			if(it!=c[i+1].end())continue;
			rep(x,0,(1<<sz[i])-1){
				if(x>>j&1)continue;
				g[x]=max(g[x],g[x|(1<<j)]);
			}
		}
	}
	rep(j,0,(1<<sz[len])-1){
		ans=max(ans,f[len&1][j]);
	}
	printf("%d",ans);
	return 0;
}