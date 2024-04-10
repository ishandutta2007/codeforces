#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    int x, d, cu=1;
    cin>>x>>d;
    vector <int> an;
    while(x)
    {
        for(int a=30; a>=0; a--)
        {
            if((1ll<<a)-1<=x)
            {
                for(int b=0; b<a; b++) an.push_back(cu);
                cu+=d, x-=(1ll<<a)-1;
                break;
            }
        }
    }
    cout<<an.size()<<"\n";
    for(int a=0; a<an.size(); a++) cout<<an[a]<<" ";
}