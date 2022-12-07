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
        scanf("%d%d", &n, &m);
        int an[n][m], ok=1;
        for(int a=0; a<n; a++)
        {
            for(int b=0; b<m; b++)
            {
                int x;
                scanf("%d", &x);
                int q=4;
                if(a==0) q--;
                if(a==n-1) q--;
                if(b==0) q--;
                if(b==m-1) q--;

                if(x<=q) an[a][b]=q;
                else ok=0;
            }
        }
        if(ok)
        {
            printf("YES\n");
            for(int a=0; a<n; a++)
            {
                for(int b=0; b<m; b++) printf("%d ", an[a][b]);
                printf("\n");
            }
        }
        else printf("NO\n");
    }
}