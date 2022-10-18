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
const int MAXN=1e5+10,MAXK=600,INF=1e9;
const int px[4]={-1,0,1,0},py[4]={0,1,0,-1};
int t,n,k;
int cnt[MAXK][MAXK][4];
int vis[MAXK*MAXK],dis[MAXK*MAXK];
vector<pi>e[MAXK*MAXK];
struct Node{
    int u,dis;
    bool operator<(const Node& n2)const{return dis>n2.dis;}
};
priority_queue<Node>q;
int H(int i,int j){return i*(k+1)+(j+1);}
int D(int x,int y,int d){
    int dx=k/2-x,dy=k/2-y;
    x+=2*dx;y+=2*dy;
    if(d==0)d=2;
    else if(d==1)d=3;
    else if(d==2)d=0;
    else if(d==3)d=1;
    return cnt[x][y][d];
}
int valid(int x,int y){return x>=0 && x<=k && y>=0 && y<=k;}
void solve(){
    scanf("%d%d",&n,&k);
    rep(x,0,k)rep(y,0,k)rep(z,0,3)cnt[x][y][z]=0;
    rep(i,1,n){
        int x1,y1,x2,y2;scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        if(x1==x2){
            if(y1>y2)swap(y1,y2);
            cnt[x1][y1][0]++;
            cnt[x1-1][y1][2]++;
        }else{
            if(x1>x2)swap(x1,x2);
            cnt[x1][y1-1][1]++;
            cnt[x1][y1][3]++;
        }
    }
    int s=H(k/2,k/2),end=H(k,k)+1;
    rep(i,0,end)e[i].clear(),vis[i]=0,dis[i]=INF;
    rep(i,0,k)rep(j,0,k){
        if(i==0 || j==0 || i==k || j==k){
            e[H(i,j)].pb(mp(end,0));
        }else{
            rep(d,0,3){
                int x=i+px[d],y=j+py[d];
                if(!valid(x,y))continue;
                e[H(i,j)].push_back(mp(H(x,y),cnt[i][j][d]+D(i,j,d)));
            }
        }
    }
    dis[s]=0;q.push(((Node){s,0}));
    while(q.size()){
        Node tmp=q.top();q.pop();
        if(vis[tmp.u])continue;
        vis[tmp.u]=1;
        for(auto p:e[tmp.u]){
            if(dis[p.fr]>dis[tmp.u]+p.se){
                dis[p.fr]=dis[tmp.u]+p.se;
                q.push(((Node){p.fr,dis[p.fr]}));
            }
        }
    }
    printf("%d\n",n-dis[end]);
}
int main(){
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}