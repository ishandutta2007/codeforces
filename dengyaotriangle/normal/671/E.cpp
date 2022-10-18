#include<bits/stdc++.h>
//dengyaotriangle!
using namespace std;
 
const int maxn=100005;
 
int n,k,tp;
int w[maxn],g[maxn];
 
int sx[maxn],sp;
long long sy[maxn];
 
long long pfx[maxn];
long long sfx[maxn];

struct node{
    long long smin,zmin,ts;
    node *c[2];
}pool[maxn*2];int ps;

void pd(node *rt){
    if(!rt)return;
    rt->smin+=rt->ts;
    if(rt->c[0]){
        rt->c[0]->ts+=rt->ts;
        rt->c[1]->ts+=rt->ts;
    }
    rt->ts=0;
}
void pu(node *rt){
    rt->zmin=min(rt->c[0]->zmin,rt->c[1]->zmin);
    rt->smin=min(rt->c[0]->smin,rt->c[1]->smin);
}
 
 
long long si[maxn],oi[maxn];
 
void chg(node *rt,int cl,int cr,int l,int r,long long sd){
    pd(rt);
    int cm=(cl+cr)>>1;
    if(l==cl&&r==cr){
        rt->ts+=sd;
        pd(rt);
    }else{
        if(r<=cm)chg(rt->c[0],cl,cm,l,r,sd),pd(rt->c[1]);
        else if(l>cm)chg(rt->c[1],cm+1,cr,l,r,sd),pd(rt->c[0]);
        else chg(rt->c[0],cl,cm,l,cm,sd),chg(rt->c[1],cm+1,cr,cm+1,r,sd);
        pu(rt);
    }
}

int qry(node *rt,int cl,int cr,int rb,long long z){
    pd(rt);pd(rt->c[0]);
    if(rt->zmin-z>k)return -1;
    if(cl==cr)return (rt->zmin-min(z,rt->smin)<=k?cl:-1);
    int cm=(cl+cr)>>1;
    if(rb<=cm)return qry(rt->c[0],cl,cm,rb,z);
    else{
        int w1=qry(rt->c[1],cm+1,cr,rb,min(z,rt->c[0]->smin));
        if(w1!=-1)return w1;
        return qry(rt->c[0],cl,cm,cm,z);
    }
}
 
const long long inf=1e18;
node *bt(int l,int r){
    node *rt=pool+ps++;
    if(l!=r){
        rt->c[0]=bt(l,(l+r)>>1);
        rt->c[1]=bt(((l+r)>>1)+1,r);
        pu(rt);
    }else{
        rt->smin=inf+sfx[l];rt->zmin=sfx[l+1];
    }
    return rt;
}

int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;i++)scanf("%d",w+i);
    for(int i=1;i<=n;i++)scanf("%d",g+i);
    pfx[1]=0;for(int i=2;i<=n;i++)pfx[i]=pfx[i-1]+g[i-1]-w[i-1];
    sx[1]=n;sy[1]=pfx[n];sp=1;
    sx[0]=n+1;
    int ans=1;
    sfx[n]=0;
    for(int j=n-1;j>=1;j--)sfx[j]=sfx[j+1]+g[j+1]-w[j];
    node *rt=bt(1,n-1);
    for(int i=n-1;i>=1;i--){
        while(sp&&pfx[i]<sy[sp]){
            sp--;
            if(sp){
                chg(rt,1,n-1,sx[sp]-1,n-1,sy[sp+1]-sy[sp]);
            }
        }
        if(sp){
            chg(rt,1,n-1,sx[sp]-1,n-1,-pfx[i]+sy[sp]);
        }
        ++sp;sx[sp]=i;sy[sp]=pfx[i];
        chg(rt,1,n-1,i,i,-inf);
        long long trg=pfx[i]-k;
        int id=lower_bound(sy+1,sy+1+sp,trg)-sy-1;
        int rb=sx[id];
        int ci=qry(rt,1,n-1,rb-1,inf*3);
        if(ci!=-1)ans=max(ans,ci-i+2);
    }
    printf("%d",ans);
    return 0;
}