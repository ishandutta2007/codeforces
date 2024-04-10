#include <bits/stdc++.h>
using namespace std;
const int inf=2e9+10;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, ta, tb, k;
    cin>>n>>m>>ta>>tb>>k;

    int ar[n], ar2[m];
    for(int a=0; a<n; a++) scanf("%d", &ar[a]);
    for(int a=0; a<m; a++) scanf("%d", &ar2[a]);

    int yk=0, an=-1;
    for(int a=0; a<=k; a++)
    {
        if(a<n)
        {
            while(yk<m and ar2[yk]<ar[a]+ta) yk++;
            if(yk+(k-a)<m) an=max(an, ar2[yk+(k-a)]+tb);
            else an=inf;
        }
        else an=inf;
    }
    if(an==inf) cout<<-1;
    else cout<<an;
}