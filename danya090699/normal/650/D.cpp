#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
bool comp(int a, int b){return (a>b);}
bool comp2(int *a, int *b){return (a[0]<b[0]);}
bool comp3(int *a, int *b){return (a[2]<b[2]);}
int main()
{
    ifstream in("input.txt");
    int n, m, inf=2e9, mle=0;
    scanf("%d%d", &n, &m);
    int ar[n], *zap[m], cha[n][2], ub[n+1], voz[n+1];
    for(int a=0; a<n; a++) scanf("%d", &ar[a]);
    for(int a=0; a<m; a++)
    {
        zap[a]=new int[4];
        scanf("%d%d", &zap[a][0], &zap[a][1]);
        zap[a][0]--;
        zap[a][2]=a;
    }
    for(int a=1; a<=n; a++)
    {
        voz[a]=inf, ub[a]=-inf;
    }
    voz[0]=0, ub[0]=inf;
    for(int a=n-1; a>=0; a--)
    {
        int pos=lower_bound(ub, ub+n+1, ar[a], comp)-ub;
        cha[a][0]=pos, cha[a][1]=ub[pos];
        ub[pos]=ar[a];
        mle=max(mle, pos);
    }
    sort(zap, zap+m, comp2);
    int yk=0, q=0;
    bool poss[n];
    for(int a=0; a<n; a++) poss[a]=0;
    ub[cha[0][0]]=cha[0][1];
    if(ub[mle]>0)
    {
        poss[0]=1, q++;
    }
    for(int a=0; a<n; a++)
    {
        while(yk<m)
        {
            if(zap[yk][0]==a)
            {
                int va=zap[yk][1], lq, rq, le=mle;
                lq=lower_bound(voz, voz+n+1, va)-voz-1;
                rq=lower_bound(ub, ub+n+1, va, comp)-ub-1;
                zap[yk][3]=lq+1+rq;
                if(q==0) le--;
                zap[yk][3]=max(zap[yk][3], le);
                yk++;
            }
            else break;
        }
        if(a!=n-1)
        {
            int ch1=lower_bound(voz, voz+n+1, ar[a])-voz, ch2=cha[a+1][0];
            voz[ch1]=ar[a], ub[ch2]=cha[a+1][1];
            int check1=ch1, check2=mle-ch2;
            int nva=0, prva=poss[check1];
            if(voz[check1]<ub[mle-check1]) nva=1;
            poss[check1]=nva, q+=nva-prva;
            nva=0, prva=poss[check2];
            if(voz[check2]<ub[mle-check2]) nva=1;
            poss[check2]=nva, q+=nva-prva;
        }
    }
    sort(zap, zap+m, comp3);
    for(int a=0; a<m; a++) printf("%d\n", zap[a][3]); //cout<<zap[a][3]<<"\n";
}