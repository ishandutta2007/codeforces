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
const int MAXN=2e5+10;
int q,n;
char s[MAXN],t[MAXN];
int a[MAXN],b[MAXN],x,y;
void solve(){
    cin>>n;
    cin>>(s+1)>>(t+1);
    if(s[1]!=t[1] || s[n]!=t[n]){cout<<-1<<'\n';return;}
    x=0,y=0;
    int cnt=1;
    rep(i,2,n){
        if(s[i]!=s[i-1]){
            a[++x]=cnt;
            cnt=1;
        }else cnt++;
    }
    a[++x]=cnt;
    cnt=1;
    rep(i,2,n){
        if(t[i]!=t[i-1]){
            b[++y]=cnt;
            cnt=1;
        }else cnt++;
    }
    b[++y]=cnt;
    if(x!=y){
        cout<<-1<<'\n';return;
    }
    ll ans=0;
    ll s1=0,s2=0;
    rep(i,1,x)a[i]--,b[i]--;
    rep(i,1,x){
        s1+=a[i];s2+=b[i];
        ans+=abs(s2-s1);
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin>>q;
    while(q--)solve();

    return 0;
}