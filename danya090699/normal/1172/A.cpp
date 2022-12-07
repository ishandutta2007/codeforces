#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[2][n], p1=-1;
    for(int i=0; i<2; i++) for(int a=0; a<n; a++) scanf("%d", &ar[i][a]);
    for(int a=0; a<n; a++) if(ar[1][a]==1) p1=a;
    if(p1!=-1)
    {
        bool ok=1;
        for(int a=p1; a<n; a++) if(ar[1][a]!=a-p1+1) ok=0;
        int q[n+1];
        for(int a=0; a<=n; a++) q[a]=0;
        for(int a=0; a<n; a++) q[ar[0][a]]=1;
        if(ok)
        {
            for(int a=0; a<p1; a++)
            {
                if(q[n-p1+a+1])
                {
                    q[ar[1][a]]++;
                }
                else
                {
                    ok=0;
                    break;
                }
            }
        }
        if(ok)
        {
            cout<<p1;
            return 0;
        }
    }
    int l=n-1, r=n*2;
    while(r-l>1)
    {
        int mid=(l+r)>>1, q[n+1], yk=mid-n, ok=1, cu=1;

        for(int a=1; a<=n; a++) q[a]=0;
        for(int a=0; a<n; a++) q[ar[0][a]]=1;
        for(int a=0; a<mid-n; a++) q[ar[1][a]]=1;

        for(int a=1; a<=n; a++)
        {
            if(q[a])
            {
                if(yk<n)
                {
                    q[ar[1][yk]]++, yk++;
                }
            }
            else
            {
                ok=0;
                break;
            }
        }

        if(ok) r=mid;
        else l=mid;
    }
    cout<<r;
}