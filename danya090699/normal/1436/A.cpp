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
            int x;
            cin>>x;
            m-=x;
        }
        if(m==0) cout<<"YES\n";
        else cout<<"NO\n";
    }
}