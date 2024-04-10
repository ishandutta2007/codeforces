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
const int MAXN=1e6+10,LIM=2e7+10;
ll n,m,f[25],ans;
bitset<LIM>pre,now;
int main(){
    cin>>n>>m;
    rep(i,1,20){
        now.reset();
        rep(j,1,m)now[i*j]=1;
        pre=pre|now;
        f[i]=pre.count();
    }
    now.reset();
    ans=1;
    rep(i,2,n){
        if(now[i])continue;
        ll cnt=0,num=i;
        while(num<=n){
            cnt++;now[num]=1;
            num=num*i;
        }
        ans+=f[cnt];
    }
    cout<<ans<<endl;
    return 0;
}