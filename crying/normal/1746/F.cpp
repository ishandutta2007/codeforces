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
mt19937 rnd(time(NULL));
const int MAXN=3e5+10,MOD=1e9;
const int MAXM=6e5+10;
int n,q,a[MAXN];
int b[MAXM],tot;
int type[MAXN],pos[MAXN],val[MAXN],l[MAXN],r[MAXN],k[MAXN];
struct BIT{
    ll t[MAXN];
    void upd(int x,int v){
        for(;x<=n;x+=lowbit(x))t[x]+=v;
    }
    ll qry(int x,ll S=0){
        for(;x;x-=lowbit(x))S+=t[x];
        return S;
    }
    ll q(ll L,ll R){
        return qry(R)-qry(L-1);
    }
}bit[30];
int key[MAXM][30];
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>q;
    rep(i,1,n){
        cin>>a[i];b[++tot]=a[i];
    }

    rep(i,1,q){
        cin>>type[i];
        if(type[i]==1){
            cin>>pos[i]>>val[i];
            b[++tot]=val[i];
        }else{
            cin>>l[i]>>r[i]>>k[i];
        }
    }
    sort(b+1,b+1+tot);
    tot=unique(b+1,b+1+tot)-b-1;

    rep(i,1,n)a[i]=lower_bound(b+1,b+1+tot,a[i])-b;
    rep(i,1,q){
        if(type[i]==1){
            val[i]=lower_bound(b+1,b+1+tot,val[i])-b;
        }
    }

    rep(i,1,tot)rep(j,0,29)key[i][j]=rnd();
    

    rep(i,1,n)rep(j,0,29)bit[j].upd(i,key[a[i]][j]);

    rep(i,1,q){
        if(type[i]==1){
            
            rep(j,0,29)bit[j].upd(pos[i],-key[a[pos[i]]][j]);

            a[pos[i]]=val[i];
            
            rep(j,0,29)bit[j].upd(pos[i],key[a[pos[i]]][j]);
        }else{

            int flag=1;
            rep(j,0,29)flag&=(bit[j].q(l[i],r[i])%k[i]==0);
            if(flag)cout<<"YES\n";
            else cout<<"NO\n";
        }
    }

    return 0;
}