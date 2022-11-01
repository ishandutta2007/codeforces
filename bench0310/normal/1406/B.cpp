#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<ll> pos,neg;
        bool zero=0;
        for(int i=0;i<n;i++)
        {
            ll a;
            cin >> a;
            if(a==0) zero=1;
            else if(a>0) pos.push_back(a);
            else if(a<0) neg.push_back(a);
        }
        sort(pos.begin(),pos.end());
        sort(neg.begin(),neg.end(),greater<ll>());
        ll res=-(1ll<<60);
        if(zero) res=0;
        for(int i=0;i<=5;i++)
        {
            if((int)pos.size()<i||(int)neg.size()<5-i) continue;
            ll x=1;
            for(int j=0;j<i;j++) x*=pos[pos.size()-j-1];
            for(int j=0;j<5-i;j++) x*=neg[neg.size()-j-1];
            res=max(res,x);
            x=1;
            for(int j=0;j<i;j++) x*=pos[j];
            for(int j=0;j<5-i;j++) x*=neg[j];
            res=max(res,x);
        }
        cout << res << "\n";
    }
    return 0;
}