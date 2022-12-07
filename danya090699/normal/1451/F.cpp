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
        int ar[n][m];
        for(int a=0; a<n; a++) for(int b=0; b<m; b++) scanf("%d", &ar[a][b]);
        string an="Jeel";
        for(int a=0; a<n+m-1; a++)
        {
            int su=0;
            for(int b=0; b<n; b++)
            {
                if(a-b>=0 and a-b<m) su^=ar[b][a-b];
            }
            if(su) an="Ashish";
        }
        cout<<an<<"\n";
    }
}