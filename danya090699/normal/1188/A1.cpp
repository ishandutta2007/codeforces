#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int q[n];
    for(int a=0; a<n; a++) q[a]=0;
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        q[u]++, q[v]++;
    }
    for(int a=0; a<n; a++)
    {
        if(q[a]==2)
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
}