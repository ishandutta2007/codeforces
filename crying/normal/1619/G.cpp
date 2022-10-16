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
const int MAXN=2e5+10,IFN=2e9;
int T,n,k,x[MAXN],y[MAXN],t[MAXN];
int bx[MAXN],by[MAXN],xt,yt;
int fa[MAXN],minn[MAXN];
vector<array<int,2> >px[MAXN],py[MAXN];
int Find(int x){if(fa[x]==x)return x;return fa[x]=Find(fa[x]);}
void Merge(int u,int v){int p=Find(u),q=Find(v);if(p==q)return;minn[p]=min(minn[p],minn[q]);fa[q]=p;}
vector<int>arr;
deque<int>s;
void solve(){
    cin>>n>>k;
    xt=yt=0;
    rep(i,1,n){
        cin>>x[i]>>y[i]>>t[i];
        bx[++xt]=x[i];by[++yt]=y[i];
        fa[i]=i,minn[i]=t[i];
    }
    sort(bx+1,bx+xt+1);sort(by+1,by+yt+1);
    xt=unique(bx+1,bx+xt+1)-bx-1;yt=unique(by+1,by+yt+1)-by-1;
    rep(i,1,n){x[i]=lower_bound(bx+1,bx+xt+1,x[i])-bx;y[i]=lower_bound(by+1,by+yt+1,y[i])-by;}
    rep(i,1,xt)px[i].clear();rep(i,1,yt)py[i].clear();
    rep(i,1,n){
        px[x[i]].push_back({y[i],i});
        py[y[i]].push_back({x[i],i});
    }
    rep(i,1,xt){
        sort(px[i].begin(),px[i].end());
        int sz=px[i].size();
        rep(j,1,sz-1){
            if(by[px[i][j][0]]-by[px[i][j-1][0]]<=k)Merge(px[i][j][1],px[i][j-1][1]);
        }
    }
    rep(i,1,yt){
        sort(py[i].begin(),py[i].end());
        int sz=py[i].size();
        rep(j,1,sz-1){
            if(bx[py[i][j][0]]-bx[py[i][j-1][0]]<=k)Merge(py[i][j][1],py[i][j-1][1]);
        }
    }
    arr.clear();
    rep(i,1,n)if(Find(i)==i)arr.push_back(minn[i]);
    sort(arr.begin(),arr.end());
    while(s.size())s.pop_back();
    for(auto u:arr)s.push_back(u);
    for(int cur=0;;cur++){
        while(s.size() && s.front()==cur)s.pop_front();
        if(s.empty()){printf("%d\n",cur);return;}
        s.pop_back();
        if(s.empty()){printf("%d\n",cur);return;}
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)solve();

    return 0;
}