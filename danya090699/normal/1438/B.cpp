#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n, ok=0;
        cin>>n;
        set <int> se;
        for(int a=0; a<n; a++)
        {
            int x;
            scanf("%d", &x);
            if(se.find(x)!=se.end()) ok=1;
            se.insert(x);
        }
        if(ok) cout<<"YES\n";
        else cout<<"NO\n";
    }
}