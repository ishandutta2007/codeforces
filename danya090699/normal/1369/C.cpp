#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int ar[n], q[k];
        for(int a=0; a<n; a++) scanf("%d", &ar[a]);
        for(int a=0; a<k; a++) scanf("%d", &q[a]);
        sort(ar, ar+n);
        long long an=0;
        for(int a=n-k; a<n; a++) an+=ar[a];
        sort(q, q+k);
        int yk=n-k, yk2=n-1;
        for(int a=0; a<k; a++)
        {
            if(q[a]>1)
            {
                yk-=q[a]-1;
                an+=ar[yk];
            }
            else an+=ar[yk2--];
        }
        printf("%lld\n", an);
    }
}