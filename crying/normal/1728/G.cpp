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
const ll MAXN=3e5+10,mod=998244353;
void add(ll& x,ll y){x=(x+y)%mod;}
ll d,n,m,q,tag[MAXN],pos[MAXN],base;
ll pre[20],suf[20],mid[20][20];
ll F[20],G[20];
int main(){
    ios::sync_with_stdio(false);
    cin>>d>>n>>m;
    base=1;rep(i,1,n+1)base=1ll*base*(d+1)%mod;
    rep(i,1,n){ll tmp;cin>>tmp;tag[tmp]=1;}
    rep(i,1,m){cin>>pos[i];}sort(pos+1,pos+1+m);
    rep(i,1,m){
        pre[i]=suf[i]=1;
        rep(j,1,d)if(tag[j]){
            if(j<pos[i])pre[i]=pre[i]*(pos[i]-j)%mod;
            else suf[i]=suf[i]*(j-pos[i])%mod;
        }
    }
    rep(i,1,m)rep(j,i+1,m){
        mid[i][j]=1;
        rep(k,pos[i]+1,pos[j]-1)if(tag[k])mid[i][j]=mid[i][j]*min(k-pos[i],pos[j]-k)%mod;
    }

    rep(i,1,m){
        F[i]=(mod-1)*pre[i]%mod;
        rep(j,1,i-1)add(F[i],(mod-1)*F[j]%mod*mid[j][i]%mod);
    }
    per(i,m,1){
        G[i]=(mod-1)*suf[i]%mod;
        rep(j,i+1,m)add(G[i],(mod-1)*G[j]%mod*mid[i][j]%mod);
    }

    cin>>q;
    rep(i,1,q){
        ll p;cin>>p;
        ll ans=0;
        //  
        rep(j,1,m){
            if(pos[j]<p) add(ans,F[j]*suf[j]%mod*(p-pos[j])%mod);
            else add(ans,G[j]*pre[j]%mod*(pos[j]-p)%mod);
        }
        rep(j,1,m)rep(k,j+1,m)if(pos[j]<p && pos[k]>p){
            add(ans,F[j]*G[k]%mod*mid[j][k]%mod*min(p-pos[j],pos[k]-p)%mod);
        }
        //
        add(ans,base);
        cout<<ans<<"\n";
    }
    return 0;
}