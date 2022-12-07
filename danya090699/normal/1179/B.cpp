#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    for(int a=1; n+1-a>a; a++)
    {
        for(int b=1; b<=m; b++) printf("%d %d\n%d %d\n", a, b, n+1-a, m+1-b);
    }
    if(n&1)
    {
        for(int a=1; m+1-a>=a; a++)
        {
            printf("%d %d\n", n/2+1, a);
            if(a!=m+1-a) printf("%d %d\n", n/2+1, m+1-a);
        }
    }
}