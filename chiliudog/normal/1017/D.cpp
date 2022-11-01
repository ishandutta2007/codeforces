#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<cassert>
#include<queue>
#include<cmath>
#include<queue>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define forE(i,x) for(int i=head[x];i!=-1;i=ne[i])
using namespace std;
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned u32;
typedef pair<int,int> pin;
#define mk(a,b) make_pair(a,b)
#define lowbit(x) ((x)&(-(x)))
#define sqr(a) ((a)*(a))
#define clr(a) (memset((a),0,sizeof(a)))
#define mid (((l)+(r))>>1)
#define pb push_back
#define w1 first
#define w2 second
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
inline void judge(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
}
/*******************************head*******************************/
const int maxn=5005;
int ans[maxn][105],n,m,q,w[maxn];
int cnt[maxn];
inline void dfs(int x,int v,int curk,int ns){
	if(curk>100)return;
	if(x==n){
		ans[v][curk]+=cnt[ns];
		return;
	}
	rep(nxt,0,1){
		dfs(x+1,v,curk+w[x]*(!(((v>>x)&1)^nxt)),ns|(nxt<<(x)));
	}
}
char s[20];
int main(){
	read(n);read(m);read(q);
	rep(i,1,n)read(w[i-1]);reverse(w,w+n);
	rep(i,1,m){
		scanf("%s",s+1);
		int res=0;
		rep(j,1,n){
			res=res*2+s[j]-'0';
		}
		cnt[res]++;
	}
	rep(i,0,(1<<n)-1){
		dfs(0,i,0,0);
		rep(j,1,100)ans[i][j]+=ans[i][j-1];
	}
	while(q--){
		scanf("%s",s+1);int k;read(k);
		int res=0;
		rep(j,1,n){
			res=res*2+s[j]-'0';
		}
		printf("%d\n",ans[res][k]);
	}
	return 0;
}