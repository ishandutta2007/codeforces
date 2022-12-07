#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
int n, m, ar[sz], l[sz], r[sz];
map <int, int> mal, mar;
int f(int t, int p, int ty)
{
    int re;
    if(ty==0)
    {
        re=p-(m+1-t);
        if(mal.find(t+p)!=mal.end()) re=r[mal[t+p]];
    }
    else
    {
        re=p+(m+1-t);
        if(mar.find(t-p)!=mar.end()) re=l[mar[t-p]];
    }
    return re;
}
main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>m;
    if(n==1)
    {
        cout<<0;
        return 0;
    }
    for(int a=1; a<=m; a++) scanf("%d", &ar[a]);
    for(int a=m; a; a--)
    {
        l[a]=f(a, ar[a]-1, 1);
        r[a]=f(a, ar[a]+1, 0);
        mal[a+ar[a]]=a;
        mar[a-ar[a]]=a;
    }
    long long an=0;
    for(int a=1; a<=n; a++)
    {
        int lg=max(1, f(0, a, 0)), rg=min(n, f(0, a, 1));
        an+=rg-lg+1;
    }
    cout<<an;
}