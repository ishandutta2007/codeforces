#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf=4e18;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, sub=0, sus=0;
    cin>>n>>m;
    vector <int> st, p, r;
    vector <pair <int, int> > pref;
    st.push_back(0), p.push_back(0), pref.push_back({0, 0}), r.push_back(inf);
    for(int a=0; a<m; a++)
    {
        int ty;
        scanf("%lld", &ty);
        if(ty==1 or ty==2)
        {
            int k;
            scanf("%lld", &k);
            if(ty==1)
            {
                sub=0, sus=0;
                st.clear(), p.clear(), pref.clear(), r.clear();
                st.push_back(0), p.push_back(0), pref.push_back({0, 0}), r.push_back(inf);
            }
            if(ty==2)
            {
                while(st.size())
                {
                    int i=st.back();
                    int va=(sub-pref[i].first)+(sus-pref[i].second)*p[i];
                    if(va)
                    {
                        int rg=sus+(va-1)/(n-p[i]);
                        if(rg>=r[i]) st.pop_back();
                        else
                        {
                            r.push_back(rg), st.push_back(p.size());
                            break;
                        }
                    }
                    else
                    {
                        r.push_back(0);
                        break;
                    }
                }
                p.push_back(n), pref.push_back({sub, sus});
            }
            n+=k;
        }
        else
        {
            int b, s;
            scanf("%lld%lld", &b, &s);
            sub+=b, sus+=s;
            while(r[st.back()]<sus) st.pop_back();
        }
        int i=st.back();
        printf("%lld %lld\n", p[i]+1, (sub-pref[i].first)+(sus-pref[i].second)*p[i]);
    }
}