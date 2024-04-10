#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int ar[n], us[n];
        for(int a=0; a<n; a++)
        {
            cin>>ar[a];
            us[a]=0;
        }
        int d=0;
        for(int a=0; a<n; a++)
        {
            int ma=0, i;
            for(int b=0; b<n; b++)
            {
                if(!us[b] and __gcd(ar[b], d)>ma)
                {
                    ma=__gcd(ar[b], d), i=b;
                }
            }
            cout<<ar[i]<<" ";
            us[i]=1, d=__gcd(d, ar[i]);
        }
        cout<<"\n";
    }
}