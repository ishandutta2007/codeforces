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
const int MAXN=1e5+10,INF=1e9,LIM=3.14e8;
int m,n,l[MAXN],st[MAXN],cnt[MAXN],ins[MAXN];
map<int,int>occ[MAXN];
set<int>s1[MAXN],s2[MAXN];
int ans[MAXN][2];
vector<int>e1[MAXN],e2[MAXN],from[MAXN];
struct Node{
    int u,dis;
    bool operator<(const Node& n2)const{return dis>n2.dis;}
};
priority_queue<Node>q;
int vis[MAXN],dis[MAXN];
queue<int>qu;
void output();
int dfs(int u){
    vis[u]=1;
    if(ans[u][0]==-1)return ans[u][1]=ans[u][0]=-1;
    ins[u]=1;
    for(int idx:from[u]){
        //idx
        int ret=0,val,flag1=1,flag2=1;
        for(pi p:occ[idx]){
            int v=p.fr,w=p.se; //wv
            if(ans[v][0]==-1){flag1=0;continue;}
            if(ins[v]){flag2=0;continue;}
            val=vis[v]?ans[v][1]:dfs(v);
            if(val==-2){flag2=0;continue;}
            ret=Min(LIM,ret+1ll*w*val);
        }
        if(!flag1)continue;
        if(!flag2){ins[u]=0;return ans[u][1]=-2;}
        ret=min(LIM,ret+cnt[idx]);
        ans[u][1]=max(ans[u][1],ret);
    }
    ins[u]=0;
    return ans[u][1];
}
int main(){
    scanf("%d%d",&m,&n);
    rep(i,1,m){
        int tmp;scanf("%d%d",&st[i],&l[i]);
        from[st[i]].pb(i);
        rep(j,1,l[i]){
            scanf("%d",&tmp);
            if(tmp==-1)cnt[i]++;
            else{
                occ[i][tmp]++;
                s1[tmp].is(i);
            }
        }
    }
    //calculate min
    rep(i,0,n)dis[i]=INF;
    rep(i,1,m){
        if(occ[i].size()==0){
            dis[st[i]]=min(dis[st[i]],cnt[i]);
            q.push(((Node){st[i],dis[st[i]]}));
        }
    }
    while(q.size()){
        Node tmp=q.top();q.pop();
        int u=tmp.u;if(vis[u])continue;
        vis[u]=1;
        for(int idx:s1[u]){
            int v=st[idx],w=cnt[idx];
            s2[idx].is(u);
            if(s2[idx].size()==occ[idx].size()){
                int sum=0;
                for(auto p:occ[idx]){
                    sum=min((ll)LIM,sum+1ll*p.se*dis[p.fr]);
                }
                sum=min(LIM,sum+w);
                if(dis[v]>sum){
                    dis[v]=sum;
                    q.push(((Node){v,dis[v]}));
                }
            }
        }
    }
    rep(i,1,n)if(dis[i]==INF)ans[i][0]=-1;else ans[i][0]=dis[i];
    //calculate max
    memset(vis,0,sizeof vis);
    rep(i,1,n){
        if(vis[i])continue;
        dfs(i);
    }
    output();
    return 0;
}
void output(){
    rep(i,1,n){
        if(ans[i][0]==-1)printf("-1 -1\n");
        else printf("%d %d\n",ans[i][0],ans[i][1]);
    }
}