#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf=3e18;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, t;
    cin>>n>>t;
    int ar[n], add[n+1][2], q[2]={0, 0}, l[n], r[n], ok=1;
    for(int a=0; a<n; a++)
    {
        l[a]=-inf, r[a]=inf;
        scanf("%lld", &ar[a]);
        for(int b=0; b<2; b++) add[a][b]=0;
    }
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%lld", &x);
        x--;
        if(x>=a)
        {
            add[0][0]++, add[a][0]--;
            add[x+1][0]++, add[n][0]--;
            add[a][1]++, add[x][1]--;
            l[x]=max(l[x], ar[a]+t);
            if(x+1<n) r[x]=min(r[x], ar[x+1]+t-1);
        }
        else ok=0;
    }
    int pr=0, an[n];
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<2; b++)
        {
            q[b]+=add[a][b];
            if(q[b]) l[a]=max(l[a], ar[a+b]+t);
        }
        an[a]=max(pr+1, l[a]);
        if(an[a]>r[a])
        {
            ok=0;
            break;
        }
        pr=an[a];
    }
    if(ok)
    {
        cout<<"Yes\n";
        for(int a=0; a<n; a++) printf("%lld ", an[a]);
    }
    else cout<<"No";
}