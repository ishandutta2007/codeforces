#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        set <int> se;
        for(int a=0; a<n; a++)
        {
            int x;
            scanf("%d", &x);
            se.insert(x);
        }
        for(int a=1; a<=n and se.size()<k; a++) se.insert(a);
        if(se.size()>k) cout<<"-1\n";
        else
        {
            cout<<n*k<<"\n";
            for(int a=0; a<n; a++)
            {
                for(auto it=se.begin(); it!=se.end(); it++) printf("%d ", *it);
            }
            cout<<"\n";
        }
    }
}