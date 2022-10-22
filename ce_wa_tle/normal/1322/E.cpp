#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;typedef long double ld;const ll N=5e5+7,Q=2e5+7,K=N,V=42;typedef ll aN[N];
void qmax(ll&a,ll b){if(a<b)a=b;}
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}aN a,c;
struct mq{
    int(*const cmp)(ll x,ll y);ll h,t;aN q;mq(int(*const f)(ll x,ll y)):cmp(f),h(1),t(0){}
    void push(ll x){while(h<=t&&cmp(x,q[t]))t--;q[++t]=x;}void pop(ll x){while(h<=t&&q[h]<=x)h++;}
    ll top()const{return h<=t?q[h]:0;}
};int cmp1(ll x,ll y){return x&&y?a[x]<a[y]:!!x;}int cmp2(ll x,ll y){return x&&y?a[x]>a[y]:!!x;}aN ans;ll maxlen=0;
ll qy(int(*const cmp)(ll x,ll y),ll x,ll y){return cmp(x,y)?x:y;}
struct qr{
    mq min[2],max[2];ll l;qr():min{cmp1,cmp1},max{cmp2,cmp2}{l=1;}
    int can_push(ll r)const{
        return l>=r||cmp1(max[~r&1].top(),qy(cmp1,min[r&1].top(),r))||
                    cmp2(min[~r&1].top(),qy(cmp2,max[r&1].top(),r));
    }
    void push(ll r){max[r&1].push(r),min[r&1].push(r),getans(r);};
    void pop(ll r){max[l&1].pop(l),min[l&1].pop(l),l++,getans(r);}
    void getans(ll r)const{
        /*printf("%lld %lld\n",l,r);*/if((r^l)&1)return;/*printf("r=%lld %lld\n",l,r);*/
        ll m=(l+r)>>1;maxlen=std::max(maxlen,m-l);
        ans[m]=a[(l&1)[(cmp1(max[~l&1].top(),min[l&1].top())?min:max)].top()];
    }
    void add(ll r){getans(r-1);while(!can_push(r))pop(r-1);push(r);}
}q;
int main(){
    ll n=readll();rep(i,1,n)a[c[i]=i]=readll();
    rep(i,1,n)q.add(i);while(q.l<n)q.pop(n);printf("%lld\n",maxlen);rep(i,1,n)printf("%lld ",ans[i]);
    return 0;
}
/*
Maintain the longest alternating interval ending with r
        
        //00101010 ??//l-1 can't be 1 before 0 between l and r,r+1 no limit
        // l     r
        //    m
//    res=00000??? ??
//change 0->1
//    res=0???1??? ?? 
        
*/
//
///*
//a     =[10][0101][101010][010][01][1][101][1][1010101][1]
//res   =[10][0011][111000][000][01][1][111][1][1111111][1]
//
//[01010101]->[00001111]
//[0101010] ->[0000000]
//[10101010]->[11110000]
//[1010101] ->[1111111]
//...0][0][0...
//...0][0  1...
//...1  0][0...
//...1  0  1...
//
//...0  1  0...
//...0  1][1...
//...1][1  0...
//...1][1][1...
//
//
//0][0...0]->0][00000]
//1  0...0]->1  11000]
//
//0][0....1]->0][000111]
//1  0....1]->1  111111]
//
//0  1.. .0]->0  000000]
//1][1. ..0]->1][111000]
//
//0  1...1]->0  00111]
//1][1...1]->1][11111]
//
//*/