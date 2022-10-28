#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int nb,nc,ns,pb,pc,ps,qb=0,qc=0,qs=0;
long long r,ans=0,sum=0;
char rec[105];
void solve()
{
    int minz;
    while((nb!=0&&qb!=0)||(nc!=0&&qc!=0)||(ns!=0&&qs!=0))
    {

        minz=10000;
        if(qb!=0)
            minz=min(nb/qb,minz);
        if(qc!=0)
            minz=min(nc/qc,minz);
        if(qs!=0)
            minz=min(ns/qs,minz);
        ans+=minz;
        nb-=minz*qb;
        nc-=minz*qc;
        ns-=minz*qs;
        if(!((nb!=0&&qb!=0)||(nc!=0&&qc!=0)||(ns!=0&&qs!=0)))
          return;
        if(nb<qb)
        {
            if(r>=(qb-nb)*pb)
            {
                r-=(qb-nb)*pb;
                nb=qb;
            }
            else
                return;
        }
        if(nc<qc)
        {
            if(r>=(qc-nc)*pc)
            {
                r-=(qc-nc)*pc;
                nc=qc;
            }
            else
                return;
        }
        if(ns<qs)
        {
            if(r>=(qs-ns)*ps)
            {
                r-=(qs-ns)*ps;
                ns=qs;
            }
            else
                return;
        }
    }
}

int main()
{
    int len,i;
    scanf("%s",rec);
    len=strlen(rec);
    scanf("%d%d%d%d%d%d",&nb,&ns,&nc,&pb,&ps,&pc);
    cin>>r;
    for(i=0;i<len;i++)
    {
        if(rec[i]=='B')
        {
            qb++;
            sum+=pb;
        }
        if(rec[i]=='C')
        {
            sum+=pc;
            qc++;
        }
        if(rec[i]=='S')
        {
            sum+=ps;
            qs++;
        }
    }
    //return 0;
    solve();
    ans+=r/sum;
    cout<<ans<<endl;
    return 0;
}