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
        string s, an;
        cin>>n>>k>>s;
        char ar[n];
        for(int a=0; a<n; a++) ar[a]=s[a];
        sort(ar, ar+n);
        if(ar[0]!=ar[k-1]) cout<<ar[k-1]<<"\n";
        else
        {
            string an;
            an.push_back(ar[0]);
            if(n>k)
            {
                if(ar[k]==ar[n-1])
                {
                    int q=(n-k)/k+(((n-k)%k)>0);
                    for(int a=0; a<q; a++) an.push_back(ar[k]);
                }
                else
                {
                    for(int a=k; a<n; a++) an.push_back(ar[a]);
                }
            }
            cout<<an<<"\n";
        }
    }
}