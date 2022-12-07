#include <bits/stdc++.h>
using namespace std;
const int inf=2e9;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t)
    {
        t--;
        int n;
        scanf("%d", &n);
        int ar[n];
        for(int a=0; a<n; a++) scanf("%d", &ar[a]);
        int ma[n+1];
        for(int a=0; a<=n; a++) ma[a]=0;
        int m;
        scanf("%d", &m);
        for(int a=0; a<m; a++)
        {
            int p, s;
            scanf("%d%d", &p, &s);
            ma[s]=max(ma[s], p);
        }
        for(int a=n-1; a>=0; a--) ma[a]=max(ma[a], ma[a+1]);
        int yk=0, an=0, err=0;
        while(yk<n)
        {
            int q=0, p=0;
            while(yk<n)
            {
                if(max(p, ar[yk])<=ma[q+1]) p=max(p, ar[yk]), yk++, q++;
                else break;
            }
            //cout<<q<<" ";
            if(q==0)
            {
                err=1;
                break;
            }
            an++;
        }
        if(err) an=-1;
        printf("%d\n", an);
    }
}