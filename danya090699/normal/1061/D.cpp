#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, x, y, pr=-1, q=0, yk=0, an=0;
    cin>>n>>x>>y;
    vector <pair <int, int> > sp;
    for(int a=0; a<n; a++)
    {
        int l, r;
        scanf("%lld%lld", &l, &r);
        r++;
        sp.push_back({l, 1ll});
        sp.push_back({r, 0ll});
    }
    sort(sp.begin(), sp.end());
    vector <int> st;
    while(yk<sp.size())
    {
        int cu=sp[yk].first, addy=q;
        if(pr!=-1)
        {
            int qq=(q*(cu-pr-1))%mod;
            an=(an+qq*y)%mod;
        }
        while(yk<sp.size())
        {
            if(sp[yk].first==cu)
            {
                if(sp[yk].second)
                {
                    int add=x;
                    if(st.size())
                    {
                        if((cu+1-st.back())*y<x)
                        {
                            add=(cu+1-st.back())*y, st.pop_back();
                        }
                    }
                    an=(an+add)%mod, q++;
                }
                else st.push_back(cu), addy--, q--;
                yk++;
            }
            else break;
        }
        //cout<<addy<<" ";
        an=(an+addy*y)%mod;
        pr=cu;
    }
    cout<<an;
}