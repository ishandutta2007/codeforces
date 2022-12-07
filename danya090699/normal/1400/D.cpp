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
        int ar[n];
        vector <int> sp[n];
        for(int a=0; a<n; a++)
        {
            cin>>ar[a];
            ar[a]--;
            sp[ar[a]].push_back(a);
        }
        long long an=0;
        for(int a=0; a<n; a++)
        {
            for(int b=a+1; b<n; b++)
            {
                int x=ar[a], y=ar[b];
                int q1=lower_bound(sp[y].begin(), sp[y].end(), a)-sp[y].begin();
                int q2=sp[x].end()-upper_bound(sp[x].begin(), sp[x].end(), b);
                an+=q1*q2;
            }
        }
        cout<<an<<"\n";
    }
}