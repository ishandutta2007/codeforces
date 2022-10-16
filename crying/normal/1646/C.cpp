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
const ll MAXN=20;
ll func(ll n){
    ll ret=1;
    rep(i,2,n)ret*=i;
    return ret;
}
ll F[MAXN];
map<ll,int>g;
ll T,n;
int main(){
    rep(i,1,15)F[i]=func(i);
    rep(i,0,(1<<15)-1){
        ll sum=0,cnt=0;
        rep(j,0,14)if(i>>j&1)sum+=F[j+1],cnt++;
        if(g.find(sum)==g.end())g[sum]=cnt;
        else if(g[sum]>cnt)g[sum]=cnt;
    }
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--){
        cin>>n;
        int ret=__builtin_popcountll(n);
        for(auto u:g){
            ll num=u.first;
            if(num>n)continue;
            ll tmp=n-num;
            if(tmp>>1&1)continue;
            ret=min(ret,__builtin_popcountll(tmp)+u.second);
        }
        cout<<ret<<endl;
    }

    return 0;
}