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
const int MAXN=1010,INF=1e9;
int T,n,m,ans=INF;
char s[MAXN][MAXN];
void solve(){
    cin>>n>>m;
    rep(i,1,n){
        cin>>(s[i]+1);
    }
    int minx=INF,maxx=-INF,miny=INF,maxy=-INF;
    rep(i,1,n)rep(j,1,m)if(s[i][j]=='B'){
        minx=min(minx,i+j);
        maxx=max(maxx,i+j);
        miny=min(miny,i-j);
        maxy=max(maxy,i-j);
    }
    ans=INF;int rx=0,ry=0;
    rep(i,1,n)rep(j,1,m){
        int x=i+j,y=i-j;
        int retx=max(abs(x-minx),abs(x-maxx));
        int rety=max(abs(y-miny),abs(y-maxy));
        int ret=max(retx,rety);
        if(ret<ans){
            ans=ret;
            rx=i;ry=j;
        }
    }
    cout<<rx<<' '<<ry<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)solve();

    return 0;
}