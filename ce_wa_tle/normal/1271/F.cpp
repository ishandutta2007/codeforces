#include<bits/stdc++.h>
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&s)
#define IO(x...)freopen(#x".in","r",stdin),freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(flush)
typedef long long ll;char is[1<<22],os[1<<22],*i1=is,*i2=is,*o1=os;
int fpc(int c){return*o1++=c;}int fgc(){return i1==i2&&is==(i2=is+fread(i1=is,1,1<<21,stdin))?-1:*i1++;}
void flush(){fwrite(os,o1-os,1,stdout);}int(*gc)()=getchar,(*pc)(int)=putchar;int qmax(ll&a,ll b){return a<b?a=b,1:0;}
ll readll(){ll x=0,w=1;int c=gc();for(;c<48||c>57;c=gc())c-45||(w=-w);for(;c>47&&c<58;c=gc())x=x*10+c-48;return x*w;}
int readchar(int l=48,int r=122){if(l>r)std::swap(l,r);int c=gc();for(;c<l||c>r;c=gc());return c;}
inline ll max(ll a,ll b,ll c){return a<b?b<c?c:b:a<c?c:a;}
inline ll min(ll a,ll b,ll c){return a>b?b>c?c:b:a>c?c:a;}ll a[3],b[3],d[8];const ll sx[]={0,7,3,5,1,6,2,4};
void calc(){
    rep(i,0,2)a[i]=readll();rep(i,0,2)b[i]=readll();rep(i,1,7)d[sx[i]]=readll();//rep(i,1,7)printf("%lld\n",d[i]);
    rep(i,0,2){ll x=a[i]+b[i];rep(k,0,3)x-=d[k+(k>>i<<i)+(1<<i)];if(x<0)return(void)puts("-1");}
    ll si=d[3],ui=min(a[0],a[1],si),di=max(si-b[0],si-b[1],0ll);rep(i,di,ui){
    ll sj=d[5],uj=min(a[0]-i,a[2],sj),dj=max(sj-b[0]+si-i,sj-b[2],0ll);rep(j,dj,uj){
    ll sk=d[6],uk=min(a[1]-i,a[2]-j,sk),dk=max(sk-b[1]+si-i,sk-b[2]+sj-j,0ll);rep(k,dk,uk){
        if(min(a[0]-i-j,a[1]-i-k,a[2]-j-k)+min(b[0]-si+i-sj+j,b[1]-si+i-sk+k,b[2]-sj+j-sk+k)>=d[7]){
        ll e7=std::min(d[7],min(a[0]-i-j,a[1]-i-k,a[2]-j-k));printf("%lld %lld %lld %lld %lld %lld %lld\n",
        e7,i,j,std::min(d[1],a[0]-i-j-e7),k,std::min(d[2],a[1]-i-k-e7),std::min(d[4],a[2]-j-k-e7));return;}
    }
    }
    }puts("-1");
}int main(){ll t=readll();while(t --> 0)calc();return 0;}