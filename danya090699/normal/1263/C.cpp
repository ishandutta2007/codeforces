#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t)
    {
        t--;
        int n;
        cin>>n;
        vector <int> an, t;
        an.push_back(0);
        for(int a=1; a*a<=n; a++)
        {
            an.push_back(a);
            if(n/a!=a) t.push_back(n/a);
        }
        while(t.size())
        {
            an.push_back(t.back());
            t.pop_back();
        }
        cout<<an.size()<<"\n";
        for(int a=0; a<an.size(); a++) printf("%d ", an[a]);
        cout<<"\n";
    }
}