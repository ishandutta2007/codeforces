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
const int MAXN=3e5+10,LIM=3e5;
int n,q,a[MAXN];
int b[MAXN],tot;
struct BIT{
    ll t[MAXN];
    int n=LIM;
    void upd(int x,ll val){for(;x<=n;x+=lowbit(x))t[x]+=val;}
    ll qry(int x,ll s=0){for(;x;x-=lowbit(x))s+=t[x];return s;}
};
struct Seg{
    BIT t1,t2;
    void upd(int l,int r,ll val){
        t1.upd(l,val);t2.upd(l,l*val);
        t1.upd(r+1,-val);t2.upd(r+1,-(r+1)*val);
    }
    ll qry(int l){
        if(!l)return 0;
        return (l+1)*t1.qry(l)-t2.qry(l);
    }   
    ll qry(int l,int r){return qry(r)-qry(l-1);}
}seg;
int solve(){
    int sum=seg.qry(1,LIM);
    int L=1,R=LIM,ret=0;
    while(L<=R){
        int mid=(L+R)>>1;
        int val=seg.qry(1,mid);
        if(val<sum){
            L=mid+1;
        }else{
            ret=mid;
            R=mid-1;
        }
    }
    return ret;
}
void Add(int pos){
    if(seg.qry(pos,pos)==0){
        seg.upd(pos,pos,1);
        return;
    }
    int L=pos+1,R=LIM,ret=pos;
    while(L<=R){
        int mid=(L+R)>>1;
        if(seg.qry(pos,mid)==mid-pos+1){
            ret=mid;L=mid+1;
        }else{
            R=mid-1;
        }
    }
    seg.upd(pos,ret,-1);
    seg.upd(ret+1,ret+1,1);
}
void Del(int pos){
    if(seg.qry(pos,pos)==1){
        seg.upd(pos,pos,-1);
        return;
    }
    int L=pos+1,R=LIM,ret=pos;
    while(L<=R){
        int mid=(L+R)>>1;
        if(seg.qry(pos,mid)==0){
            ret=mid;L=mid+1;
        }else{
            R=mid-1;
        }
    }
    seg.upd(pos,ret,1);
    seg.upd(ret+1,ret+1,-1);
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>q;
    rep(i,1,n)cin>>a[i],tot=max(tot,a[i]),b[a[i]]++;
    rep(i,1,tot){
        if(b[i]>=2){
            b[i+1]+=b[i]/2;
            b[i]%=2;
            tot=max(tot,i+1);
        }
    }
    rep(i,1,tot)seg.upd(i,i,b[i]);
    rep(i,1,q){
        int pos,val;cin>>pos>>val;
        Add(val);
        Del(a[pos]);
        a[pos]=val;
        cout<<solve()<<'\n';
    }


    return 0;
}