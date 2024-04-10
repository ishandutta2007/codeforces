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
        for(int a=0; a<n; a++) cin>>ar[a];
        vector <int> an;
        int yk=0;
        while(yk<n)
        {
            if(ar[yk])
            {
                int q=0;
                while(yk<n and ar[yk]) q++, yk++;
                if(q&1) q--;
                for(int a=0; a<q; a++) an.push_back(1);
            }
            else an.push_back(0), yk++;
        }
        cout<<an.size()<<"\n";
        for(int a=0; a<an.size(); a++) cout<<an[a]<<" ";
        cout<<"\n";
    }
}