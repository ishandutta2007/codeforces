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
const int MAXN=4e5+10,px[4]={-1,0,1,0},py[4]={0,-1,0,1};
int n,m,cnt;
vector<int>a[MAXN],tag[MAXN],vis[MAXN],num[MAXN];
int valid(int x,int y){return x>=1 && x<=n && y>=1 && y<=m;}
int check(int x,int y){return a[x][y]==1 || num[x][y]>0;}
vector<array<int,2> >invalid,S;
set<array<int,2> >tmpS;
ll ans;
void solve(int x1,int y1,int x2,int y2){
    if(!tag[x1][y1])cnt-=check(x1,y1),tag[x1][y1]=1;
    if(!tag[x2][y2])cnt-=check(x2,y2),tag[x2][y2]=1;
    rep(k,0,3){
        int cx=x1+px[k],cy=y1+py[k];
        if(valid(cx,cy) && !tag[cx][cy])cnt-=check(cx,cy),tag[cx][cy]=1;
        cx=x2+px[k],cy=y2+py[k];
        if(valid(cx,cy) && !tag[cx][cy])cnt-=check(cx,cy),tag[cx][cy]=1;
    }
    rep(k,0,3){
        int cx=x1+px[k],cy=y1+py[k];
        if(valid(cx,cy) && a[cx][cy]>a[x1][y1] && (cx!=x2 || cy!=y2))num[cx][cy]--;
        cx=x2+px[k],cy=y2+py[k];
        if(valid(cx,cy) && a[cx][cy]>a[x2][y2] && (cx!=x1 || cy!=y1))num[cx][cy]--;
    }
    num[x1][y1]=num[x2][y2]=0;
    swap(a[x1][y1],a[x2][y2]);
    rep(k,0,3){
        int cx=x1+px[k],cy=y1+py[k];
        if(valid(cx,cy) && a[cx][cy]>a[x1][y1] && (cx!=x2 || cy!=y2))num[cx][cy]++;
        if(valid(cx,cy) && a[cx][cy]<a[x1][y1])num[x1][y1]++;
        cx=x2+px[k],cy=y2+py[k];
        if(valid(cx,cy) && a[cx][cy]>a[x2][y2] && (cx!=x1 || cy!=y1))num[cx][cy]++;
        if(valid(cx,cy) && a[cx][cy]<a[x2][y2])num[x2][y2]++;
    }
    if(tag[x1][y1])cnt+=check(x1,y1),tag[x1][y1]=0;
    if(tag[x2][y2])cnt+=check(x2,y2),tag[x2][y2]=0;
    rep(k,0,3){
        int cx=x1+px[k],cy=y1+py[k];
        if(valid(cx,cy) && tag[cx][cy])cnt+=check(cx,cy),tag[cx][cy]=0;
        cx=x2+px[k],cy=y2+py[k];
        if(valid(cx,cy) && tag[cx][cy])cnt+=check(cx,cy),tag[cx][cy]=0;
    }
}
int check(int x1,int y1,int x2,int y2){
    solve(x1,y1,x2,y2);
    int ret=(cnt==n*m);
    solve(x1,y1,x2,y2);
    return ret;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    cnt=n*m;
    rep(i,1,n){
        a[i].resize(m+1);
        tag[i].resize(m+1);
        vis[i].resize(m+1);
        num[i].resize(m+1);
        rep(j,1,m)cin>>a[i][j],tag[i][j]=0,vis[i][j]=0,num[i][j]=0;
    }
    rep(i,1,n)rep(j,1,m){
        rep(k,0,3){
            int x=i+px[k],y=j+py[k];
            if(valid(x,y) && a[x][y]<a[i][j])num[i][j]++;
        }
    }
    rep(i,1,n)rep(j,1,m)if(!check(i,j))invalid.push_back({i,j}),cnt--,vis[i][j]=1;
    if(!invalid.size()){cout<<0;return 0;}
    if(invalid.size()>4){cout<<2;return 0;}
    for(auto u:invalid){
        int x=u[0],y=u[1];
        tmpS.insert({x,y});
        rep(k,0,3){
            int cx=x+px[k],cy=y+py[k];
            if(valid(cx,cy))tmpS.insert({cx,cy});
        }
    }
    for(auto u:tmpS)S.push_back(u);
    for(auto u:S){
        rep(x,1,n)rep(y,1,m){
            if(!vis[u[0]][u[1]] && a[x][y]>a[u[0]][u[1]])continue;
            if(x!=u[0] || y!=u[1])ans+=check(u[0],u[1],x,y);
        }
    }
    int sz=S.size();
    rep(i,0,sz-1)rep(j,i+1,sz-1)ans-=check(S[i][0],S[i][1],S[j][0],S[j][1]);
    if(ans)cout<<"1 "<<ans;
    else cout<<2;
    return 0;
}