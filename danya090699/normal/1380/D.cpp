#include <bits/stdc++.h>
#define int long long
using namespace std;
void err()
{
    cout<<-1;
    exit(0);
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, x, k, y;
    cin>>n>>m>>x>>k>>y;
    int p[n+2], ar2[n+2];
    p[0]=0, p[1]=n+1;
    ar2[0]=0, ar2[n+1]=1;
    for(int a=1; a<=n; a++)
    {
        int x;
        cin>>x;
        x++;
        p[x]=a;
        ar2[a]=x;
    }
    int ar[m+2], an=0;
    ar[0]=0, ar[m+1]=1;
    for(int a=1; a<=m; a++)
    {
        cin>>ar[a];
        ar[a]++;
    }
    //for(int a=0; a<m+2; a++) cout<<ar[a]<<" ";
    for(int a=0; a<=m; a++)
    {
        int lg=p[ar[a]], rg=p[ar[a+1]], ma=max(ar[a], ar[a+1]);
        //cout<<ar[a+1]<<"\n";
        if(lg>rg) err();

        int fo=0;
        for(int b=lg+1; b<rg; b++)
        {
            if(ar2[b]>ma) fo=1;
        }
        int q=rg-lg-1;
        if(fo) q-=k, an+=x;

        if(q<0) err();

        an+=min(q/k*x+q%k*y, q*y);
    }
    cout<<an;
}