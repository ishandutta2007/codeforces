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
const int maxn=1e7+5;
int n,a[maxn],cnt[maxn],nxt[maxn][2],tot,root;
inline void add(int &x,int p,int w){
	if(!x)x=++tot;
	cnt[x]++;
	if(w==-1)return;
	add(nxt[x][(p>>w)&1],p,w-1);
}
int main(){
	read(n);
	rep(i,1,n)read(a[i]);
	rep(i,1,n){
		int p;read(p);
		add(root,p,29);
	}
	rep(i,1,n){
		int ans=0,cur=root;
		per(w,29,0){
			int v=(a[i]>>w)&1;
			if(cnt[nxt[cur][v]])cur=nxt[cur][v];
			else ans+=1<<w,cur=nxt[cur][!v];
			cnt[cur]--;
		}
		printf("%d ",ans);
	}
	return 0;
}