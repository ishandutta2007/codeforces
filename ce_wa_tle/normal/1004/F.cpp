#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;const ll N=2e5+9,inf=1e9+7;typedef ll aN[N];aN a;
ll readll(){
    ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
    for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
ll x_;const ll&x=x_;struct node{ll ans,ln,rn,ly[22],lx[22],ry[22],rx[22];node(){memset(this,0,sizeof*this);}
void print()const{printf(".ans=%lld\n",ans);ref(i,0,ln)printf("[%lld]=%lld\n",lx[i],ly[i]);puts("");ref(i,0,rn)printf("[%lld]=%lld\n",rx[i],ry[i]);};
node(ll w,ll b):node(){ans=b>=x,ln=2,rn=2,lx[0]=rx[0]=w,ly[0]=ry[0]=b,lx[1]=w+1,rx[1]=w-1,ly[1]=ry[1]=(1<<22)-1;}}val[N<<1];
void merge(node&w,const node&u,const node&v){
//    puts("----------------------------------------merge");u.print(),v.print();
    ll now;w.ans=u.ans+v.ans;ll j=v.ln-1,r=v.lx[j];
    ref(i,0,u.rn-1){while(j>0&&(u.ry[i]|v.ly[j-1])>=x)j--;w.ans+=(u.rx[i]-u.rx[i+1])*(r-v.lx[j])/*,printf("%lld %lld %lld %lld\n",i,j,u.rx[i]-u.rx[i+1],r-v.lx[j])*/;}
    memcpy(w.ly,u.ly,sizeof(ll)*(u.ln)),memcpy(w.lx,u.lx,sizeof(ll)*(u.ln));
    now=w.ly[(w.ln=u.ln-1)-1];ref(i,0,v.ln)if(v.ly[i]&~now)w.ly[w.ln++]=now|=v.ly[i],w.lx[w.ln-1]=v.lx[i];//,printf("%lld\n",w.lx[i]);
    memcpy(w.ry,v.ry,sizeof(ll)*(v.rn)),memcpy(w.rx,v.rx,sizeof(ll)*(v.rn));
    now=w.ry[(w.rn=v.rn-1)-1];ref(i,0,u.rn)if(u.ry[i]&~now)w.ry[w.rn++]=now|=u.ry[i],w.rx[w.rn-1]=u.rx[i];
//    w.print();
//    puts(""); 
}struct sgt{
    void build(ll u,ll l,ll r){
        if(l==r){val[u]=node(l,a[l]);return;}ll mid=(l+r)>>1;
        build(u<<1,l,mid),build(u<<1|1,mid+1,r),merge(val[u],val[u<<1],val[u<<1|1]);
    }void update(ll u,ll l,ll r,ll q,ll c){
        if(l==r){val[u]=node(l,c);return;}ll mid=(l+r)>>1;
        if(q<=mid)update(u<<1,l,mid,q,c);else update(u<<1|1,mid+1,r,q,c);merge(val[u],val[u<<1],val[u<<1|1]);
    }node query(ll u,ll l,ll r,ll ql,ll qr){
        if(ql<=l&&r<=qr)return val[u];ll mid=(l+r)>>1;
        if(qr<mid+1)return query(u<<1,l,mid,ql,qr);if(ql>mid)return query(u<<1|1,mid+1,r,ql,qr);
        node res;merge(res,query(u<<1,l,mid,ql,qr),query(u<<1|1,mid+1,r,ql,qr));return res;
    }
}t;
int main(){
    ll n=readll(),m=readll(),u;::x_=readll();rep(i,1,n)a[i]=readll();t.build(1,1,n);//return 0;
    rep(i,1,m)if(readll()==1)u=readll(),t.update(1,1,n,u,readll());
    else u=readll(),printf("%lld\n",t.query(1,1,n,u,readll()).ans);return 0;
}