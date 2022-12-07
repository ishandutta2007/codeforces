#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n, p=0, c=0, ok=1;
        scanf("%d", &n);
        for(int a=0; a<n; a++)
        {
            int cp, cc;
            scanf("%d%d", &cp, &cc);

            if(cp<p or cc<c) ok=0;
            if(cp-p<cc-c) ok=0;

            p=cp, c=cc;
        }
        printf(ok ? "YES\n" : "NO\n");
    }
}