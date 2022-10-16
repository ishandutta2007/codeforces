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
const int MAXN=6,mod=998244353;
int n,m,x[MAXN],y[MAXN];
int f[32][22][22][22][22][2][2],lim[32];
int dp(int d,int addxp,int addxn,int addyp,int addyn,int lx,int ly){
    if(d==30)return (addxp==0) && (addxn==0) && (addyp==0) && (addyn==0) && (lx==0) && (ly==0);
    int& ret=f[d][addxp][addxn][addyp][addyn][lx][ly];if(~ret)return ret;
    ret=0;
    rep(mask,0,(1<<n)-1){
        int px=0,nx=0,py=0,ny=0;
        rep(i,1,n)if(mask>>(i-1)&1){
            if(x[i]>0)px+=x[i];else nx-=x[i];
            if(y[i]>0)py+=y[i];else ny-=y[i];
        }
        int xp=addxp+px,xn=addxn+nx,yp=addyp+py,yn=addyn+ny;
        if((xp&1)!=(xn&1) || (yp&1)!=(yn&1))continue;
        int fx=lx;if(lim[d+1]==1 && (xp&1)==0)fx=0;if(lim[d+1]==0 && (xp&1)==1)fx=1;
        int fy=ly;if(lim[d+1]==1 && (yp&1)==0)fy=0;if(lim[d+1]==0 && (yp&1)==1)fy=1;
        ret=(ret+dp(d+1,xp>>1,xn>>1,yp>>1,yn>>1,fx,fy))%mod;
    }
    return ret;
}
int main(){
    cin>>n>>m;
    rep(i,1,n)cin>>x[i]>>y[i];
    memset(f,-1,sizeof f);
    int num=m;
    rep(i,1,30){
        lim[i]=num&1;
        num>>=1;   
    }
    int ans=dp(0,0,0,0,0,0,0);ans=(ans-1+mod)%mod;
    cout<<ans<<endl;
    return 0;
}