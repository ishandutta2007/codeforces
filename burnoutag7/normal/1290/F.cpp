#include<bits/stdc++.h>
using namespace std;

const int mod=998244353;

int n,m,x[5],y[5],px[1<<5],py[1<<5],nx[1<<5],ny[1<<5],f[31*20*20*20*20*2*2+5],mpx,mpy,mnx,mny;

int h(int lg,int cpx,int cpy,int cnx,int cny,int sx,int sy){
    return lg*640000+cpx*32000+cpy*1600+cnx*80+cny*4+sx*2+sy;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i];
    }
    for(int s=0;s<1<<n;s++){
        for(int i=0;i<n;i++)if(s>>i&1){
            x[i]<0?(nx[s]-=x[i]):(px[s]+=x[i]);
            y[i]<0?(ny[s]-=y[i]):(py[s]+=y[i]);
        }
    }
    mpx=max(1,px[(1<<n)-1]);
    mpy=max(1,py[(1<<n)-1]);
    mnx=max(1,nx[(1<<n)-1]);
    mny=max(1,ny[(1<<n)-1]);
    f[0]=1;
    int lg;
    for(lg=0;1<<lg<=m;lg++)
        for(int cpx=0;cpx<mpx;cpx++)for(int cpy=0;cpy<mpy;cpy++)
            for(int cnx=0;cnx<mnx;cnx++)for(int cny=0;cny<mny;cny++)
                for(int sx=0;sx<2;sx++)for(int sy=0;sy<2;sy++){
                    int cur=f[h(lg,cpx,cpy,cnx,cny,sx,sy)];
                    for(int s=0;s<1<<n;s++){
                        int spx=cpx+px[s],spy=cpy+py[s];
                        int snx=cnx+nx[s],sny=cny+ny[s];
                        if(spx&1^snx&1||spy&1^sny&1)continue;
                        int bx=spx&1,by=spy&1,cbit=m>>lg&1;
                        int nsx=bx<cbit?0:bx>cbit?1:sx,nsy=by<cbit?0:by>cbit?1:sy;
                        int nxt=h(lg+1,spx>>1,spy>>1,snx>>1,sny>>1,nsx,nsy);
                        f[nxt]=(f[nxt]+cur)%mod;
                    }
                }
    int ans=f[h(lg,0,0,0,0,0,0)];
    cout<<(ans?ans-1:mod-1)<<endl;

    return 0;
}