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
        vector<int> h(n+1,0);
        for(int i=1;i<=n;i++) cin >> h[i];
        auto f=[&](int i)->int{return max(0,max(h[i-1],h[i+1])-h[i]+1);};
        vector<ll> l(n+1,0);
        for(int i=2;i<=n-1;i+=2) l[i]=l[i-2]+f(i);
        vector<ll> r(n+2,0);
        for(int i=n-1;i>=2;i-=2) r[i]=r[i+2]+f(i);
        ll res=0;
        if(n&1) res=l[n-1];
        else
        {
            res=min(l[n-2],r[3]);
            for(int i=2;i+3<=n-1;i+=2) res=min(res,l[i]+r[i+3]);
        }
        cout << res << "\n";
    }
    return 0;
}