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
        int h, n, an=0;
        scanf("%d%d", &h, &n);
        int ar[n], yk=1;
        for(int a=0; a<n; a++) scanf("%d", &ar[a]);
        while(yk<n)
        {
            int q=1;
            while(yk+1<n and ar[yk+1]==ar[yk]-1) yk++, q++;
            if(ar[yk]!=1) an+=(q&1);
            yk++;
        }
        printf("%d\n", an);
    }
}