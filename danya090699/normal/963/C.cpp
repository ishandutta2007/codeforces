#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    map <int, map <int, int> > ma;
    for(int a=0; a<n; a++)
    {
        int w, h, q;
        scanf("%lld%lld%lld", &w, &h, &q);
        ma[h][w]+=q;
    }
    int ok=1, x=0;
    for(auto it=ma.begin(); it!=ma.end(); it++)
    {
        int h=(*it).first, de=0;
        map <int, int> &cu=(*it).second;
        for(auto it2=cu.begin(); it2!=cu.end(); it2++) de=__gcd(de, (*it2).second);
        for(auto it2=cu.begin(); it2!=cu.end(); it2++) (*it2).second/=de;
        if(it!=ma.begin())
        {
            auto it3=it;
            it3--;
            map <int, int> &cu2=(*it3).second;
            if(cu.size()==cu2.size())
            {
                for(auto it2=cu.begin(), it4=cu2.begin(); it2!=cu.end(); it2++, it4++)
                {
                    if((*it2).first!=(*it4).first or (*it2).second!=(*it4).second) ok=0;
                }
            }
            else ok=0;
        }
        x=__gcd(x, de);
    }
    if(ok)
    {
        int an=0;
        for(int a=1; a*a<=x; a++)
        {
            if(x%a==0)
            {
                an+=2;
                if(a==x/a) an--;
            }
        }
        cout<<an;
    }
    else cout<<0;
}