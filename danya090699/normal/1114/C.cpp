#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf=2e18;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, x;
    cin>>n>>x;
    vector <pair <int, int> > de;
    for(int a=2; a*a<=x; a++)
    {
        if(x%a==0)
        {
            de.push_back({a, 0});
            while(x%a==0) x/=a, de.back().second++;
        }
    }
    if(x>1) de.push_back({x, 1});
    int an=inf;
    for(int a=0; a<de.size(); a++)
    {
        int cu=de[a].first, st=de[a].second, b=1, q=0;
        while(n/cu>=b)
        {
            b*=cu, q+=n/b;
        }
        an=min(an, q/st);
    }
    cout<<an;
}