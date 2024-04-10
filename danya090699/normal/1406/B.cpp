#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n, an=-1e18;
        cin>>n;
        vector <int> sp[2];
        for(int a=0; a<n; a++)
        {
            int x;
            scanf("%lld", &x);
            if(x<0) sp[0].push_back(x);
            else sp[1].push_back(x);
        }
        sort(sp[0].begin(), sp[0].end(), greater <int>());
        sort(sp[1].begin(), sp[1].end());
        for(int i=0; i<2; i++)
        {
            for(int a=0; a<=min(5ll, 0ll+sp[0].size()); a++)
            {
                if(5-a<=sp[1].size())
                {
                    int x=1;
                    for(int b=0; b<a; b++) x*=sp[0][b];
                    for(int b=0; b<5-a; b++) x*=sp[1][b];
                    an=max(an, x);
                }
            }
            reverse(sp[0].begin(), sp[0].end());
            reverse(sp[1].begin(), sp[1].end());
        }
        cout<<an<<"\n";
    }
}