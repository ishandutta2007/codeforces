#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n, x, q[2]={0, 0};
        cin>>n>>x;
        for(int a=0; a<n; a++)
        {
            int y;
            scanf("%d", &y);
            q[y&1]++;
        }
        if(q[1]%2==0) q[1]--;
        if(q[0]%2!=(x%2)^1) q[0]--;
        if(q[0]<0 or q[1]<0 or q[0]+q[1]<x) cout<<"No\n";
        else cout<<"Yes\n";
    }
}