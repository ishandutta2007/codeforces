#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t)
    {
        t--;
        int n, k;
        scanf("%d%d", &n, &k);
        k--;
        int x=1;
        while(k and n>=x)
        {
            n-=x, k--, x+=2;
        }
        if(n>=x and n&1) printf("YES\n");
        else printf("NO\n");
    }
}