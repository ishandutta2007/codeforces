#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n, mi=2e9, ma=-2e9;
        cin>>n;
        for(int a=0; a<n; a++)
        {
            int x;
            scanf("%d", &x);
            mi=min(mi, x), ma=max(ma, x);
        }
        if(mi==ma) cout<<n<<"\n";
        else cout<<"1\n";
    }
}