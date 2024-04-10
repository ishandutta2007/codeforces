#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n, ma=0, pr;
        scanf("%d", &n);
        for(int a=0; a<n; a++)
        {
            int x;
            scanf("%d", &x);
            if(a) ma=max(ma, pr-x), pr=max(pr, x);
            else pr=x;
        }
        for(int a=0; ; a++)
        {
            if(ma<(1ll<<a))
            {
                printf("%d\n", a);
                break;
            }
        }
    }
}