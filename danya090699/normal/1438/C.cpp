#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        for(int a=0; a<n; a++)
        {
            for(int b=0; b<m; b++)
            {
                int x;
                scanf("%d", &x);
                if((x&1)!=((a+b)&1)) x++;
                printf("%d ", x);
            }
            printf("\n");
        }
    }
}