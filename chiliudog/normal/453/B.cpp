#include<bits/stdc++.h>
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
#define ls ((x)<<1)
#define rs (((x)<<1)|1)
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
int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
int f[105][1<<16],tr[105][1<<16];
int s[105];
int a[105],n;
const int inf=1e9;
inline void dfs(int x,int y){
	if(x==0)return;
	dfs(x-1,y xor s[tr[x][y]]);
	printf("%d ",tr[x][y]);
}
int main(){
    read(n);rep(i,1,n)read(a[i]);
    rep(i,2,58){
    	rep(j,0,15)if(i%prime[j]==0)s[i]|=1<<j;
    }
    rep(i,0,n)rep(j,0,(1<<16)-1)f[i][j]=inf;f[0][0]=0;
    rep(i,0,n-1)rep(j,0,(1<<16)-1)if(f[i][j]!=inf){
    	f[i+1][j]=min(f[i+1][j],f[i][j]+abs(a[i+1]-1));
    	if(f[i+1][j]==f[i][j]+abs(a[i+1]-1))tr[i+1][j]=1;
    	rep(nxt,2,58)if(!(s[nxt]&j)){
    		f[i+1][j xor s[nxt]]=min(f[i+1][j xor s[nxt]],f[i][j]+abs(a[i+1]-nxt));
    		if(f[i+1][j xor s[nxt]]==f[i][j]+abs(a[i+1]-nxt))
    			tr[i+1][j xor s[nxt]]=nxt;
    	}
    }int ans=inf;
    rep(i,0,(1<<16)-1)ans=min(ans,f[n][i]);
    rep(i,0,(1<<16)-1)if(ans==f[n][i]){
    	dfs(n,i);
    	return 0;
    }
    return 0;
}