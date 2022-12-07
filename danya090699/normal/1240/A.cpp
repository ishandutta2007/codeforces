#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int q;
    cin>>q;
    while(q)
    {
        q--;
        int n, x, A, y, B;
        long long k;
        scanf("%d", &n);
        int ar[n];
        for(int a=0; a<n; a++) scanf("%d", &ar[a]);
        sort(ar, ar+n, greater <int>());
        scanf("%d%d%d%d%lld", &x, &A, &y, &B, &k);
        if(x<y) swap(A, B), swap(x, y);
        int l=0, r=n+1;
        while(r-l>1)
        {
            int mid=(l+r)>>1, q12=0, q1=0, q2=0;
            for(int a=1; a<=mid; a++)
            {
                if(a%A==0 and a%B==0) q12++;
                else if(a%A==0) q1++;
                else if(a%B==0) q2++;
            }
            int yk=0;
            long long su=0;
            for(int a=0; a<q12; a++) su+=(ar[yk++]/100)*(x+y);
            for(int a=0; a<q1; a++) su+=(ar[yk++]/100)*x;
            for(int a=0; a<q2; a++) su+=(ar[yk++]/100)*y;
            if(su>=k) r=mid;
            else l=mid;
        }
        if(r==n+1) printf("-1\n");
        else printf("%d\n", r);
    }
}