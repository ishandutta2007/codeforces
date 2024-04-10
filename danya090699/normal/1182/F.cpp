#include <bits/stdc++.h>
using namespace std;
const int sq=30000;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t)
    {
        t--;
        int l, r, p, mod;
        pair <int, int> an={2e9, -1};
        cin>>l>>r>>p>>mod;
        p%=mod;
        p*=2, mod*=2;
        map <int, int> ma;
        for(int a=0; a<sq; a++)
        {
            int va=(1ll*a*p)%mod;
            if(ma.find(va)==ma.end()) ma[va]=a;
        }
        for(int a=l; a<=r; a+=sq)
        {
            if(a+sq-1>r)
            {
                for(int b=a; b<=r; b++)
                {
                    int di=abs(mod/2-((1ll*b*p)%mod));
                    an=min(an, {di, b});
                }
            }
            else
            {
                int l=mod/2-((1ll*a*p)%mod);
                if(l<0) l+=mod;

                auto it=ma.upper_bound(l);
                if(it!=ma.begin()) it--;

                int di=abs((1ll*a*p+(*it).first)%mod - mod/2);
                an=min(an, {di, a+(*it).second});

                it++;
                if(it!=ma.end())
                {
                    int di=abs((1ll*a*p+(*it).first)%mod - mod/2);
                    an=min(an, {di, a+(*it).second});
                }
            }
        }
        cout<<an.second<<"\n";
    }
}