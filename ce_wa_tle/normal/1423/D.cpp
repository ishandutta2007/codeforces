#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;typedef unsigned long long ull;const ll N=221,M=N,K=N,T=N/10,W=1e6+7;ll c,lx,ly;
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
bool p1;
bool vis[T][K][N][M];ll map[N][M];ll wind[W];ll zh[112];const ll dx[]={0,-1,1,0,0},dy[]={0,0,0,1,-1};
const ll lim=K*T*N*M/2000;struct node{ll x,y,w,s;}q[lim];ll n,m,k,t,w,x[T],y[T],f[T];bool p2;
ll bfs(ll lx,ll ly){
//rep(i,1,n){rep(j,1,m)printf("%lld ",map[i][j]);puts("");}
    node to=q[1]=(node){lx,ly,k,0};vis[to.s][to.w][to.x][to.y]=1;rfor(ll h=1,t=1,size=1;size;){
        node now=q[size--,h==lim-1?h=0,lim-1:h++],to;
        const ll time=f[now.s]+(k-now.w),wt=wind[time+1],kx=map[now.x+dx[wt]][now.y+dy[wt]];
//        printf("%lld %lld %lld %lld\n",now.x,now.y,now.w,now.s);
        switch(map[now.x][now.y]){
            case 2:return time;
            case 3:rep(i,1,::t)if(x[i]==now.x&&y[i]==now.y&&f[i]==time)now.s=i,now.w=k;//O(T*K*T)
            case 1:if(!now.w)continue;
            ref(i,0,5)to=(node){.x=now.x+dx[i]+dx[wt],.y=now.y+dy[i]+dy[wt],.w=now.w-1,.s=now.s},
            !vis[to.s][to.w][to.x][to.y]&&map[to.x][to.y]&&(kx||map[now.x+dx[i]][now.y+dy[i]])
            &&(vis[to.s][to.w][to.x][to.y]=1,q[size++,++t==lim?t=0:t]=to,0);
        } 
    }return-1;
}
int main(){//fprintf(stderr,"%.2lfMiB\n",(&p2-&p1)/1048576.0); 
    zh['C']=0,zh['N']=1,zh['S']=2,zh['E']=3,zh['W']=4;n=readll(),m=readll(),k=readll(),t=readll(),w=readll();
    rep(i,1,n)rep(j,1,m)c=readchar(),map[i][j]=c!='L',(c=='M')&&(lx=i,ly=j),(c=='P')&&(map[i][j]=2);
    rep(i,1,w)wind[i]=zh[readchar()];rep(i,1,t)x[i]=readll()+1,y[i]=readll()+1,f[i]=readll(),map[x[i]][y[i]]=3;//exit(0);
    printf("%lld\n",bfs(lx,ly));return 0;
}