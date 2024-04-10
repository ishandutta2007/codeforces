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
const int MAXN=3010*6010,
px[8]={-1,-1,-1,0,1,1,1,0},
py[8]={-1,0,1,1,1,0,-1,-1};
int r,c,n;
int H(int i,int j){return (i-1)*(c+c)+j;}
int fa[MAXN],sz[MAXN],ans,vis[MAXN];
vector<int>lstx,lsty,lstsz;
int Find(int u){
    while(u!=fa[u])u=fa[u];
    return u;
}
int valid(int x,int y){return x>=1 && x<=r && y>=1 && y<=c+c;}
void Merge(int x,int y){
    if(sz[x]>sz[y])swap(x,y);
    lstx.pb(x);lsty.pb(y);lstsz.pb(sz[x]);
    sz[y]+=sz[x];
    fa[x]=y;
}
void Back(){
    int x=lstx.back(),y=lsty.back(),z=lstsz.back();
    lstx.pop_back();lsty.pop_back();lstsz.pop_back();
    fa[x]=x;
    sz[y]-=z;sz[x]=z;
}
void Add(int x,int y){
    vis[H(x,y)]=1;
    rep(k,0,7){
        int cx=x+px[k],cy=y+py[k];
        if(cx<1 || cx>r)continue;
        if(cy==0)cy=c+c;
        else if(cy==c+c+1)cy=1;
        if(!vis[H(cx,cy)])continue;
        int a=Find(H(x,y)),b=Find(H(cx,cy));
        if(a!=b){
            Merge(a,b);
        }
    }
}
int main(){
    scanf("%d%d%d",&r,&c,&n);
    rep(i,1,r)rep(j,1,2*c)fa[H(i,j)]=H(i,j),sz[H(i,j)]=1;
    rep(i,1,n){
        int a,b;scanf("%d%d",&a,&b);
        int cur=lstx.size();
        Add(a,b);
        Add(a,b+c);
        int p=Find(H(a,b)),q=Find(H(a,b+c));
        if(p==q){
            while(cur!=lstx.size())Back();
            vis[H(a,b)]=vis[H(a,b+c)]=0;
        }else{
            ans++;
        }
    }
    printf("%d",ans);
    return 0;
}