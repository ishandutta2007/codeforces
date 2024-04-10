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
const int MAXN=1010;
int T,n,d[MAXN];
struct DSU{
    int fa[MAXN];
    void init(){
        rep(i,1,n)fa[i]=i;
    }
    int find(int x){
        if(fa[x]==x)return x;
        return fa[x]=find(fa[x]);
    }
    void merge(int x,int y){
        x=find(x);y=find(y);
        if(x==y)return;
        fa[x]=y;
    }
}dsu;
int c[MAXN],vis[MAXN];
void output(){
    cout<<"!";
    rep(i,1,n)cout<<" "<<c[i];
    cout<<endl;
    fflush(stdout);
}
void solve(){
    cin>>n;
    rep(i,1,n)cin>>d[i];
    memset(vis,0,sizeof vis);
    dsu.init();
    for(int cnt=0;cnt<=n;){
        int p=0;
        rep(i,1,n){
            if(p==0 && !vis[i])p=i;
            else if(!vis[i] && d[p]<d[i])p=i;
        }

        vis[p]=1;cnt++;
        rep(i,1,d[p]){
            cout<<"? "<<p;cout<<endl;fflush(stdout);
            int x;cin>>x;
            int f=dsu.find(x);
            if(!vis[f]){
                dsu.fa[f]=p;
                cnt++;
                vis[f]=1;
            }else{
                dsu.fa[p]=f;
                break;
            }
        }
    }
    rep(i,1,n)c[i]=dsu.find(i);
    output();
}
int main(){
    cin>>T;
    while(T--)solve();



    return 0;
}