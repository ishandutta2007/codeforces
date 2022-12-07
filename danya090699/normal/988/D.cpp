#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    set <int> se;
    vector <int> an;
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%lld", &x);
        se.insert(x);
    }
    an.push_back(*se.begin());
    for(auto it=se.begin(); it!=se.end(); it++)
    {
        int x=(*it);
        for(int a=1; a<=(1ll<<30); a<<=1)
        {
            vector <int> cu;
            cu.push_back(x);
            if(se.find(x+a)!=se.end())
            {
                cu.push_back(x+a);
                if(a!=1 and se.find(x+a/2)!=se.end()) cu.push_back(x+a/2);
            }
            if(cu.size()>an.size())
            {
                an.clear();
                for(int b=0; b<cu.size(); b++) an.push_back(cu[b]);
            }
        }
    }
    cout<<an.size()<<"\n";
    for(int a=0; a<an.size(); a++) cout<<an[a]<<" ";
}