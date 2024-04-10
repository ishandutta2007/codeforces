#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, an=0;
    cin>>n;
    int ar[n], us[n];
    for(int a=0; a<n; a++) cin>>ar[a], us[a]=0;
    sort(ar, ar+n);
    for(int a=0; a<n; a++)
    {
        if(us[a]==0)
        {
            an++;
            for(int b=0; b<n; b++) if(ar[b]%ar[a]==0) us[b]=1;
        }
    }
    cout<<an;
}