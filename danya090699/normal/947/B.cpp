#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, su=0;
    cin>>n;
    int v[n];
    multiset <int> se;
    for(int a=0; a<n; a++) cin>>v[a];
    for(int a=0; a<n; a++)
    {
        se.insert(su+v[a]);
        int t, cu=0;
        cin>>t;
        while(se.size())
        {
            int x=*se.begin();
            if(x<=su+t)
            {
                cu+=x-su;
                se.erase(se.begin());
            }
            else break;
        }
        cu+=se.size()*1ll*t;
        su+=t;
        cout<<cu<<" ";
    }
}