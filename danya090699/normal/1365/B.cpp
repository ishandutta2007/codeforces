#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n, pr, q=0, ok=1;
        cin>>n;
        for(int a=0; a<n; a++)
        {
            int x;
            cin>>x;
            if(a and pr>x) ok=0;
            pr=x;
        }
        for(int a=0; a<n; a++)
        {
            int i;
            cin>>i;
            q+=i;
        }
        if(q!=0 and q!=n) ok|=1;
        if(ok) cout<<"Yes\n";
        else cout<<"No\n";
    }
}