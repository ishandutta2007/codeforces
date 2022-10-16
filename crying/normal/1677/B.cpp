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
const int MAXN=1e6+10;
int T,n,m;
char str[MAXN];
int a[MAXN],vis[MAXN],ans[MAXN],s[MAXN];
void solve(){
    cin>>n>>m>>(str+1);
    rep(i,0,n*m)a[i]=str[i]-'0',vis[i]=ans[i]=0;
    rep(i,1,n*m){
        s[i]=s[i-1]+a[i];
    }
    rep(o,1,m){
        int ss=0;
        for(int i=o;i<=n*m;i+=m){
            if(s[i]-s[max(0,i-m)]>0)ss++;
            ans[i]+=ss;
        }
    }
    int ss=0;
    rep(i,1,n*m){
        if(!a[i]){
            ans[i]+=ss;
            continue;
        }
        vis[i%m]++;
        if(vis[i%m]==1)ss++;
        ans[i]+=ss;
    }
    rep(i,1,n*m)cout<<ans[i]<<' ';cout<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)solve();

    return 0;
}