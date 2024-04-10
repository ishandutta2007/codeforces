#include <bits/stdc++.h>
using namespace std;
long long a,b,aux,la,lb,cif[100],ap[100],sol,best=0;
void bkt(int strat,int nr,long long sol)
{
    if(strat==la and nr==1)
    {
        best=max(best,sol);
        return;
    }
    if(strat==la and sol==aux)
    {
        best=max(best,sol);
        return;
    }
    if(nr==1)
    {
        for(int i=9;i>=0;i--)
            for(int j=1;j<=ap[i];j++)
                sol=sol*10+i;
        best=max(best,sol);
        return;
    }
    strat++;
    ///<=cif[strat] , nr=0
    if(ap[cif[strat]]>=1)
    {
        ap[cif[strat]]--;
        bkt(strat,0,sol*10+cif[strat]);
        ap[cif[strat]]++;
    }
    for(int i=cif[strat]-1;i>=0;i--)
        if(ap[i]>=1)
        {
            ap[i]--;
            bkt(strat,1,sol*10+i);
            ap[i]++;
            break;
        }
    strat--;
}
int main()
{
    cin>>a>>b;
    aux=b;
    while(a>0)
    {
        la++;
        ap[a%10]++;
        a/=10;
    }
    while(b>0)
    {
        cif[++lb]=b%10;
        b/=10;
    }
    if(la<lb)
    {
        for(int i=9;i>=0;i--)
            for(int j=1;j<=ap[i];j++)
                cout<<i;
        return 0;
    }
    for(int i=1;i<la+1-i;i++)
        swap(cif[i],cif[la+1-i]);
    bkt(0,0,0);
    cout<<best;
    return 0;
}
/**
**/