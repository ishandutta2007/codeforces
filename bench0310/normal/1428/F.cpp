#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    s="$"+s;
    vector<int> c(n+2,0);
    for(int i=n;i>=1;i--) c[i]=(s[i]=='1')*c[i+1]+(s[i]=='1');
    cout << endl;
    vector<int> bucket[n+1];
    for(int i=1;i<=n;i++) if((i==1||s[i-1]=='0')&&c[i]>0) bucket[c[i]].push_back(i);
    ll res=0;
    vector<array<int,2>> v;
    v.push_back({1,0});
    v.push_back({n+1,n});
    auto pairs=[&](ll a)->ll{return (a*(a+1)/2);};
    for(int o=n;o>=1;o--)
    {
        for(int i:bucket[o]) v.push_back({i,i+c[i]-1});
        sort(v.begin(),v.end());
        res+=pairs(n);
        for(int i=1;i<(int)v.size()-1;i++)
        {
            auto [l,r]=v[i];
            res-=(pairs(r-l+1)-pairs(r-l+1-(o-1)));
        }
        for(int i=0;i<(int)v.size()-1;i++)
        {
            auto [l1,r1]=v[i];
            auto [l2,r2]=v[i+1];
            auto [l,r]=make_pair(r1+1,l2-1);
            res-=pairs(r-l+1);
            if(r1-l1+1>=o) res-=((ll)(o-1)*(r-l+1));
            if(r2-l2+1>=o) res-=((ll)(o-1)*(r-l+1));
            if(r1-l1+1>=o&&r2-l2+1>=o) res-=((ll)(o-1)*(o-1));
        }
    }
    cout << res << "\n";
    return 0;
}