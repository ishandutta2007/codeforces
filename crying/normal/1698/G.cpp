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
const int MAXN=40;
int n,cnt;
char tmp[MAXN],s[MAXN];
ll P;
map<ll,int>f;
ll mult(__int128 a,__int128 b)
{   
    __int128 ret=0;
    rep(i,0,n)ret^=(((a>>i&1)*b)<<i);
    per(i,n+n,n+1)if(ret>>i&1)ret^=((__int128)(P)<<(i-n));
    return (ll)(ret);
}
ll bsgs(){
    ll lim=(1LL<<18),R=1;
    rep(i,0,lim-1){
        f[mult(R,P^1)]=i;
        R=mult(R,2);
    }
    ll base=R;
    rep(i,1,lim){
        if(f.find(R)!=f.end())return lim*i-f[R];
        R=mult(R,base);
    }
}
int main(){
    cin>>(tmp+1);
    int flag=0;
    for(int i=1;tmp[i];i++){
        if(!flag && tmp[i]=='0'){cnt++;continue;}
        flag=1;
        s[++n]=tmp[i];
    }
    while(n && s[n]=='0')n--;
    if(cnt==strlen(tmp+1)){cout<<-1;return 0;}
    rep(i,1,n)if(s[i]=='1')P|=(1LL<<(i-1));
    n--;
    ll val=bsgs();
    if(val==-1){cout<<-1;return 0;}
    cout<<1+cnt<<' '<<1+val+cnt;
    return 0;
}