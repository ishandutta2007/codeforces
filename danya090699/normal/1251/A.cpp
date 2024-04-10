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
        string s;
        cin>>s;
        int yk=0, n=s.size();
        set <char> se;
        while(yk<n)
        {
            char cu=s[yk];
            int q=0;
            while(yk<n and s[yk]==cu) q++, yk++;
            if(q%2) se.insert(cu);
        }
        for(auto it=se.begin(); it!=se.end(); it++) cout<<(*it);
        cout<<"\n";
    }
}