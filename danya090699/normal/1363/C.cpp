#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n, x, q=0;
        cin>>n>>x;
        for(int a=0; a<n-1; a++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            if(u==x or v==x) q++;
        }
        if(q<2) cout<<"Ayush\n";
        else
        {
            if(n&1) cout<<"Ashish\n";
            else cout<<"Ayush\n";
        }
    }
}