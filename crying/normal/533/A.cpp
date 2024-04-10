#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
const int MAXN=5e5+10,INF=1e9+10;
int n,k,h[MAXN],s[MAXN],hh[MAXN];
int pos[MAXN],lim[MAXN],rt[MAXN],depth[MAXN];
vector<int>e[MAXN],V[MAXN];
array<int,2>val[MAXN],tag[MAXN*2+10];
int tag1[MAXN],tag2[MAXN];
int cmp(array<int,2> x,array<int,2> y){
    if(x[0]!=y[0])return x[0]>y[0];
    else return depth[x[1]]<depth[y[1]];
}
int cmp2(int x,int y){return pos[x]<pos[y];}
void dfs1(int u,int fa,int m1,int m2){
    depth[u]=depth[fa]+1;
    if(h[u]<h[m1])m2=m1,m1=u;
    else if(h[u]<h[m2])m2=u;
    lim[u]=h[m2];
    val[u]={h[m1],u};
    V[m1].push_back(u);rt[u]=(m1==u);
    for(auto v:e[u])if(v!=fa)dfs1(v,u,m1,m2);
}
int st[20][MAXN],logn[MAXN],raw[MAXN];
int qry(int L,int R){
    if(L>R)return -INF;
    int len=logn[R-L+1];
    return max(st[len][L],st[len][R-(1<<len)+1]);
}
int cur1,cur2,cur;
int ed[MAXN];
void upd(int L,int R){if(L>R)return;tag[++cur]={L,1};tag[++cur]={R+1,-1};}
int check(int u,int mid){
    cur=cur1=cur2=0;
    for(auto x:V[u]){
        int p=pos[x],v=hh[p],nv=min(lim[x],v+mid);
        int R=ed[p];
        int L=lower_bound(s+1,s+1+k,nv,greater<int>())-s;
        upd(L,R-1);
    }
    //sort
    /*
    tag1[++cur1]=k+1;
    int p1=1,p2=1;
    while(p1<=cur1 && p2<=cur2){
        if(tag1[p1]<=tag2[p2]){
            tag[++cur]={tag1[p1],1};
            p1++;
        }else{
            tag[++cur]={tag2[p2],-1};
            p2++;
        }
    }
    while(p1<=cur1)tag[++cur]={tag1[p1],1},p1++;
    while(p2<=cur2)tag[++cur]={tag2[p2],-1},p2++;
    */
    tag[++cur]={k+1,1};
    sort(tag+1,tag+1+cur);
    //
    if(qry(1,tag[1][0]-1)>0)return 0;
    int sum=0;
    rep(i,1,cur){if(tag[i][0]>k)break;
        sum+=tag[i][1];
        if(tag[i][0]!=tag[i+1][0]){
            int L=tag[i][0],R=tag[i+1][0]-1;
            if(qry(L,R)>sum)return 0;
        }
    }
    return 1;
}
int check(int mid){
    rep(i,1,n)if(rt[i]){
        if(check(i,mid))return 1;
    }
    return 0;
}
int main(){
    logn[0]=-1;rep(i,1,500000)logn[i]=logn[i>>1]+1;
    ios::sync_with_stdio(false);
    cin>>n;
    rep(i,1,n)cin>>h[i];
    rep(i,1,n-1){
        int u,v;cin>>u>>v;
        e[u].push_back(v);e[v].push_back(u);
    }
    cin>>k;
    rep(i,1,k)cin>>s[i];
    sort(s+1,s+1+k,greater<int>());
    h[0]=INF;
    dfs1(1,0,0,0);
    sort(val+1,val+1+n,cmp);
    rep(i,1,n)hh[i]=val[i][0],pos[val[i][1]]=i;
    rep(i,1,n)sort(V[i].begin(),V[i].end(),cmp2);
    hh[n+1]=-INF;
    rep(i,1,k)raw[i]=st[0][i]=upper_bound(hh+1,hh+1+n,s[i],greater<int>())-hh-1,st[0][i]=i-st[0][i];
    rep(i,1,n){
        int cur=max(1,ed[i-1]);
        while(cur<=n && raw[cur]<i)cur++;
        ed[i]=cur;
    }
    rep(i,1,19)rep(j,1,k)if(j+(1<<i)-1<=k)st[i][j]=max(st[i-1][j],st[i-1][j+(1<<(i-1))]);
    if(qry(1,k)<=0){cout<<"0";return 0;}
    int L=1,R=1e9,ret=-1;
    while(L<=R){
        int mid=(L+R)>>1;
        if(check(mid)){ret=mid;R=mid-1;}
        else{L=mid+1;}
    }
    cout<<ret;
    return 0;
}