#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, p;
    cin>>n>>p;
    int ar[n];
    vector <int> an;
    for(int a=0; a<n; a++) cin>>ar[a];
    for(int x=1; x<=2000; x++)
    {
        int q[n];
        for(int a=0; a<n; a++) q[a]=0;
        for(int a=0; a<n; a++)
        {
            if(ar[a]<x) q[0]++;
            else if(ar[a]<x+n) q[ar[a]-x]++;
        }
        bool ok=1;
        for(int a=0; a<n; a++)
        {
            if(a) q[a]+=q[a-1]-1;
            if(q[a]%p==0)
            {
                ok=0;
                break;
            }
        }
        if(ok) an.push_back(x);
    }
    cout<<an.size()<<"\n";
    for(int a=0; a<an.size(); a++) cout<<an[a]<<" ";
}