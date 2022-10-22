#include<bits/stdc++.h>
#include<complex.h>
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&s)
#define IO(x...)freopen(#x".in","r",stdin),freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(flush)
typedef long long ll;const ll N=2e5+7,mod=1e9+7;typedef ll aN[N];char is[1<<22],os[1<<22],*i1=is,*i2=is,*o1=os;
int fpc(int c){return*o1++=c;}int fgc(){return i1==i2&&is==(i2=is+fread(i1=is,1,1<<21,stdin))?-1:*i1++;}
void flush(){fwrite(os,o1-os,1,stdout);}int(*gc)()=getchar,(*pc)(int)=putchar;
ll readll(){ll x=0,w=1;int c=gc();for(;c<48||c>57;c=gc())c-45||(w=-w);for(;c>=48&&c<=57;c=gc())x=x*10+c-48;return x*w;}
int readchar(int l=48,int r=122){if(l>r)std::swap(l,r);int c=gc();for(;c<l||c>r;c=gc());return c;}
aN x,y,px,nx,py,ny,c;int cmpx(ll a,ll b){return x[a]<x[b];}int cmpy(ll a,ll b){return y[a]<y[b];}
ll solve(ll hx,ll tx,ll hy,ll ty,ll n){
    assert(!px[hx]);
    assert(!nx[tx]);
    assert(!py[hy]);
    assert(!ny[ty]);//ll cnt=0;
//    rfor(ll now=hx;now;now=nx[now])cnt++;assert(cnt==n);
//    rfor(ll now=tx;now;now=px[now])cnt++;assert(cnt==2*n);
//    rfor(ll now=hy;now;now=ny[now])cnt++;assert(cnt==3*n);
//    rfor(ll now=ty;now;now=py[now])cnt++;assert(cnt==4*n);
    ll ux=hx,vx=tx,uy=hy,vy=ty,t=0;rep(i,1,n/2){
        if(x[nx[ux]]-x[ux]>1){ny[px[vx=ux,hx=nx[ux]]=0]=hy,py[nx[ux]=0]=ty;do py[ny[py[c[++t]=ux]]=ny[ux]]=py[ux];
        while(px[ux]&&(ux=px[ux]));hy=ny[0],ty=py[0];std::sort(c+1,c+t+1,cmpy),c[t+1]=0;rep(i,1,t+1)
        py[ny[c[i-1]]=c[i]]=c[i-1];uy=ny[0],vy=py[0];return solve(hx,tx,hy,ty,n-t)+solve(ux,vx,uy,vy,t);}else ux=nx[ux];
        
        if(x[vx]-x[px[vx]]>1){ny[nx[ux=vx,tx=px[vx]]=0]=hy,py[px[vx]=0]=ty;do py[ny[py[c[++t]=vx]]=ny[vx]]=py[vx];
        while(nx[vx]&&(vx=nx[vx]));hy=ny[0],ty=py[0];std::sort(c+1,c+t+1,cmpy),c[t+1]=0;rep(i,1,t+1)
        py[ny[c[i-1]]=c[i]]=c[i-1];uy=ny[0],vy=py[0];return solve(hx,tx,hy,ty,n-t)+solve(ux,vx,uy,vy,t);}else vx=px[vx];
        
        if(y[ny[uy]]-y[uy]>1){nx[py[vy=uy,hy=ny[uy]]=0]=hx,px[ny[uy]=0]=tx;do px[nx[px[c[++t]=uy]]=nx[uy]]=px[uy];
        while(py[uy]&&(uy=py[uy]));hx=nx[0],tx=px[0];std::sort(c+1,c+t+1,cmpx),c[t+1]=0;rep(i,1,t+1)
        px[nx[c[i-1]]=c[i]]=c[i-1];ux=nx[0],vx=px[0];return solve(hx,tx,hy,ty,n-t)+solve(ux,vx,uy,vy,t);}else uy=ny[uy];
        
        if(y[vy]-y[py[vy]]>1){nx[ny[uy=vy,ty=py[vy]]=0]=hx,px[py[vy]=0]=tx;do px[nx[px[c[++t]=vy]]=nx[vy]]=px[vy];
        while(ny[vy]&&(vy=ny[vy]));hx=nx[0],tx=px[0];std::sort(c+1,c+t+1,cmpx),c[t+1]=0;rep(i,1,t+1)
        px[nx[c[i-1]]=c[i]]=c[i-1];ux=nx[0],vx=px[0];return solve(hx,tx,hy,ty,n-t)+solve(ux,vx,uy,vy,t);}else vy=py[vy];
    }return 1;
}
int main(){//IO(b);
    ll n=readll();rep(i,1,n)x[i]=readll(),y[c[i]=i]=readll();
    std::sort(c+1,c+n+1,cmpx);rep(i,1,n+1)px[nx[c[i-1]]=c[i]]=c[i-1];
    std::sort(c+1,c+n+1,cmpy);rep(i,1,n+1)py[ny[c[i-1]]=c[i]]=c[i-1];
    printf("%lld\n",solve(nx[0],px[0],ny[0],py[0],n));return 0;
}
/*
10
1 1
1 3
2 3
3 3
5 1
5 2
5 3
3 7
4 7
5 7

9
0 2
0 4
0 3
0 1
0 16
0 10
0 11
0 15
0 17

*/