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
const ll MAXN=220;
ll f[MAXN];
ll T,n,c[MAXN];
ll tag[MAXN];
void solve(){
    memset(tag,0,sizeof tag);
    cin>>n;
    ll sum=0;
    rep(i,1,n)cin>>c[i],sum+=c[i];
    ll S=0,cur=0;
    while(S<sum){
        cur++;S+=f[cur];
    }
    if(S>sum){
        cout<<"NO\n";
        return;
    }
    int lst=0;
    per(i,cur,1){
        int pos=0;
        rep(j,1,n)if(c[j]>=c[pos] && lst!=j)pos=j;
        if(c[pos]<f[i]){
            cout<<"NO\n";
            return;
        }
        c[pos]-=f[i];
        lst=pos;
    }
    cout<<"YES\n";
}
int main(){
    f[1]=f[2]=1;
    rep(i,2,60){f[i]=f[i-1]+f[i-2];}
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)solve();

    return 0;
}