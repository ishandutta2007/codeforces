#include <bits/stdc++.h>
using namespace std;
const int sz=5e3+10, inf=1e9;
int dpl[sz][sz], dpr[sz][sz];
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n], lg[n], rg[n];
    for(int a=0; a<n; a++)
    {
        cin>>ar[a];
        for(int b=0; b<n; b++) dpl[a][b]=-inf, dpr[a][b]=inf;
    }
    int yk=0;
    while(yk<n)
    {
        int st=yk;
        while(yk<n)
        {
            if(ar[st]==ar[yk]) yk++;
            else break;
        }
        dpl[0][st]=yk-1, dpr[0][yk-1]=st;
        rg[st]=yk-1, lg[yk-1]=st;
    }
    for(int a=0; a<n; a++)
    {
        if(dpl[a][0]==n-1 or dpr[a][n-1]==0)
        {
            cout<<a;
            break;
        }
        for(int l=0; l<n; l++)
        {
            if(dpl[a][l]!=-inf)
            {
                int r=dpl[a][l], lc=-1, rc=-1, ll=l, rr=r;
                if(l) lc=ar[l-1], ll=lg[l-1];
                if(r+1<n) rc=ar[r+1], rr=rg[r+1];

                if(lc==rc) dpl[a+1][ll]=max(dpl[a+1][ll], rr);
                else
                {
                    if(lc!=-1) dpl[a+1][ll]=max(dpl[a+1][ll], r);
                    if(rc!=-1) dpr[a+1][rr]=min(dpr[a+1][rr], l);
                }
            }
        }
        for(int r=0; r<n; r++)
        {
            if(dpr[a][r]!=inf)
            {
                int l=dpr[a][r], lc=-1, rc=-1, ll=l, rr=r;
                if(l) lc=ar[l-1], ll=lg[l-1];
                if(r+1<n) rc=ar[r+1], rr=rg[r+1];

                if(lc==rc) dpl[a+1][ll]=max(dpl[a+1][ll], rr);
                else
                {
                    if(lc!=-1) dpl[a+1][ll]=max(dpl[a+1][ll], r);
                    if(rc!=-1) dpr[a+1][rr]=min(dpr[a+1][rr], l);
                }
            }
        }
    }
}