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
        int p, q;
        cin>>p>>q;
        vector <pair <int, int> > de;
        for(int a=2; a*a<=q; a++)
        {
            if(q%a==0)
            {
                de.push_back({a, 1});
                while(q%a==0) de.back().second*=a, q/=a;
            }
        }
        if(q>1) de.push_back({q, q});

        int an=1;
        for(int a=0; a<de.size(); a++)
        {
                int cu=p;
                while(cu%de[a].second==0) cu/=de[a].first;
                an=max(an, cu);
        }

        cout<<an<<"\n";
    }
}