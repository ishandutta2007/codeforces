/*
the vast starry sky,
bright for those who chase the light.
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mk make_pair
const int inf=(int)1e9;
const ll INF=(ll)5e18;
const int MOD=998244353;
int _abs(int x){return x<0 ? -x : x;}
int add(int x,int y){x+=y; return x>=MOD ? x-MOD : x;}
int sub(int x,int y){x-=y; return x<0 ? x+MOD : x;}
#define mul(x,y) (ll)(x)*(y)%MOD
void Add(int &x,int y){x+=y; if(x>=MOD) x-=MOD;}
void Sub(int &x,int y){x-=y; if(x<0) x+=MOD;}
void Mul(int &x,int y){x=mul(x,y);}
int qpow(int x,int y){int ret=1; while(y){if(y&1) ret=mul(ret,x); x=mul(x,x); y>>=1;} return ret;}
void checkmin(int &x,int y){if(x>y) x=y;}
void checkmax(int &x,int y){if(x<y) x=y;}
void checkmin(ll &x,ll y){if(x>y) x=y;}
void checkmax(ll &x,ll y){if(x<y) x=y;}
#define out(x) cerr<<#x<<'='<<x<<' '
#define outln(x) cerr<<#x<<'='<<x<<endl
#define sz(x) (int)(x).size()
inline int read(){
    int x=0,f=1; char c=getchar();
    while(c>'9'||c<'0'){if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
    return x*f;
}
const int N=200005;
int n,m,dp1[N][2],vis[N][2];
vector<int> v[N],G[N];
struct node2{
    int dis,id,typ;
    bool operator < (const node2 &rhs) const{
        return dis>rhs.dis;
    }
};
priority_queue<node2> q1;
void bfs1(){
    memset(vis,0,sizeof(vis));
    memset(dp1,0x3f,sizeof(dp1));
    dp1[1][0]=0; dp1[1][1]=0; q1.push({0,1,0});
    while(!q1.empty()){
        node2 u=q1.top(); q1.pop();
        if(vis[u.id][u.typ]) continue; vis[u.id][u.typ]=1;
        if(!u.typ){
            for(auto &to : v[u.id]) if(!vis[to][0]){
                if(dp1[to][0]>u.dis){
                    dp1[to][0]=u.dis;
                    q1.push({dp1[to][0],to,0});
                }
            }
            for(auto &to : G[u.id]) if(!vis[to][1]){
                if(dp1[to][1]>u.dis+1){
                    dp1[to][1]=u.dis+1;
                    q1.push({dp1[to][1],to,1});
                }
            }
        }
        else{
            for(auto &to : v[u.id]) if(!vis[to][0]){
                if(dp1[to][0]>u.dis+1){
                    dp1[to][0]=u.dis+1;
                    q1.push({dp1[to][0],to,0});
                }
            }
            for(auto &to : G[u.id]) if(!vis[to][1]){
                if(dp1[to][1]>u.dis){
                    dp1[to][1]=u.dis;
                    q1.push({dp1[to][1],to,1});
                }
            }
        }
    }
}
ll dis[N][21][2],bl[N][21][2];
struct node{
    ll dis; int id,typ,rev;
    bool operator < (const node &rhs) const{
        if(rev>=19){
            if(rev==rhs.rev) return dis>rhs.dis;
            else return rev>rhs.rev;
        }
        return dis+(1<<rev)>rhs.dis+(1<<rhs.rev);
    }
};
priority_queue<node> q;
void dijkstra(){
    memset(dis,0x3f,sizeof(dis));
    q.push({0,1,0,0});
    for(int i=0;i<=20;i++) dis[1][i][0]=0,dis[1][i][1]=0;
    while(!q.empty()){
        node u=q.top(); q.pop();
        if(bl[u.id][u.rev][u.typ]) continue;
        bl[u.id][u.rev][u.typ]=1;
        if(u.rev==20) continue;
        if(!u.typ){
            for(auto &to : v[u.id]) if(!bl[to][u.rev][0]){
                if(dis[to][u.rev][0]>u.dis+1){
                    dis[to][u.rev][0]=u.dis+1;
                    q.push({u.dis+1,to,0,u.rev});
                }
            }
            for(auto &to : G[u.id]) if(!bl[to][u.rev+1][1]){
                if(dis[to][u.rev+1][1]>u.dis+1){
                    dis[to][u.rev+1][1]=u.dis+1;
                    q.push({u.dis+1,to,1,u.rev+1});
                }
            }
        }
        else{
            for(auto &to : G[u.id]) if(!bl[to][u.rev][1]){
                if(dis[to][u.rev][1]>u.dis+1){
                    dis[to][u.rev][1]=u.dis+1;
                    q.push({u.dis+1,to,1,u.rev});
                }
            }
            for(auto &to : v[u.id]) if(!bl[to][u.rev+1][0]){
                if(dis[to][u.rev+1][0]>u.dis+1){
                    dis[to][u.rev+1][0]=u.dis+1;
                    q.push({u.dis+1,to,0,u.rev+1});
                }
            }
        }
    }
    ll ans=INF;
    for(int i=0;i<=20;i++){
        checkmin(ans,dis[n][i][0]+(1<<i)-1);
        checkmin(ans,dis[n][i][1]+(1<<i)-1);
    }
    cout<<ans%MOD<<endl;
}
int dp2[N][2];
void bfs2(){
    memset(vis,0,sizeof(vis));
    while(!q1.empty()) q1.pop();
    memset(dp2,0x3f,sizeof(dp2));
    dp2[1][0]=0; dp2[1][1]=0; q1.push({0,1,0});
    while(!q1.empty()){
        node2 u=q1.top(); q1.pop();
        if(vis[u.id][u.typ]) continue; vis[u.id][u.typ]=1;
        if(!u.typ){
            for(auto &to : v[u.id]) if(!vis[to][0]){
                if(dp2[to][0]>u.dis+1&&dp1[to][0]==dp1[u.id][0]){
                    dp2[to][0]=u.dis+1;
                    q1.push({dp2[to][0],to,0});
                }
            }
            for(auto &to : G[u.id]) if(!vis[to][1]){
                if(dp2[to][1]>u.dis+1&&dp1[to][1]==dp1[u.id][0]+1){
                    dp2[to][1]=u.dis+1;
                    q1.push({dp2[to][1],to,1});
                }
            }
        }
        else{
            for(auto &to : v[u.id]) if(!vis[to][0]){
                if(dp2[to][0]>u.dis+1&&dp1[to][0]==dp1[u.id][1]+1){
                    dp2[to][0]=u.dis+1;
                    q1.push({dp2[to][0],to,0});
                }
            }
            for(auto &to : G[u.id]) if(!vis[to][1]){
                if(dp2[to][1]>u.dis+1&&dp1[to][1]==dp1[u.id][1]){
                    dp2[to][1]=u.dis+1;
                    q1.push({dp2[to][1],to,1});
                }
            }
        }
    }
    if(dp1[n][0]<dp1[n][1]||(dp1[n][0]==dp1[n][1]&&dp2[n][0]<dp2[n][1])){
        printf("%d\n",add(qpow(2,dp1[n][0])-1,dp2[n][0]));
    }
    else{
        printf("%d\n",add(qpow(2,dp1[n][1])-1,dp2[n][1]));
    }
}

int main()
{
    n=read(); m=read();
    for(int i=1;i<=m;i++){
        int x=read(),y=read();
        v[x].push_back(y); G[y].push_back(x);
    }
    bfs1();
    if(min(dp1[n][1],dp1[n][0])<=20) dijkstra();
    else bfs2();
    return 0;
}