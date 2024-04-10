#include <bits/stdc++.h>
using namespace std;
int mo(int x)
{
    if(x<0) return -x;
    else return x;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, k, inf=1e9, fo=-1;
    cin>>n>>m>>k;
    int di[k+1], ve[k][2];
    bool us[k+1];
    for(int a=0; a<=k; a++)
    {
        di[a]=inf, us[a]=0;
    }
    for(int a=0; a<k; a++)
    {
        cin>>ve[a][0]>>ve[a][1];
        if(ve[a][0]==1 and ve[a][1]==1) di[a]=0;
        if(ve[a][0]==n and ve[a][1]==m) fo=a;
    }
    if(fo==-1) fo=k;
    for(int a=0; a<=k; a++)
    {
        int be=inf, bnu;
        for(int a=0; a<=k; a++)
        {
            if(us[a]==0 and di[a]<be)
            {
                be=di[a], bnu=a;
            }
        }
        if(be==inf) break;
        us[bnu]=1;
        int y=ve[bnu][0], x=ve[bnu][1];
        for(int a=0; a<k; a++)
        {
            if(us[a]==0)
            {
                int cy=ve[a][0], cx=ve[a][1], va=inf;
                if(mo(y-cy)+mo(x-cx)==1) va=0;
                else if(mo(y-cy)<=2 or mo(x-cx)<=2) va=1;
                di[a]=min(di[a], di[bnu]+va);
            }
        }
        if(mo(y-n)<=1 or mo(x-m)<=1) di[k]=min(di[k], di[bnu]+1);
    }
    if(di[fo]==inf) cout<<-1;
    else cout<<di[fo];
}