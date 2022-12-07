#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n], an=n;
    for(int a=0; a<n; a++) cin>>ar[a];
    for(int a=0; a<n; a++)
    {
        set <int> se;
        int ok=1;
        for(int b=0; b<a; b++)
        {
            if(se.find(ar[b])==se.end()) se.insert(ar[b]);
            else ok=0;
        }
        if(ok)
        {
            int yk=n-1;
            while(yk>=a and se.find(ar[yk])==se.end())
            {
                se.insert(ar[yk]), yk--;
            }
            an=min(an, yk-a+1);
        }
    }
    cout<<an;
}