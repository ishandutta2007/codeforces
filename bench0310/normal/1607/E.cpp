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
        auto opt=[&](int n,vector<int> a)->int
        {
            int mn=0,mx=0;
            int now=0;
            for(int x:a)
            {
                now+=x;
                mn=min(mn,now);
                mx=max(mx,now);
                if(mx-mn==n)
                {
                    now-=x;
                    if(x==1) return n-now;
                    else return 1-now;
                }
            }
            return n-mx;
        };
        int n,m;
        cin >> n >> m;
        string s;
        cin >> s;
        vector<int> v,h;
        for(char c:s)
        {
            if(c=='U') v.push_back(-1);
            if(c=='D') v.push_back(1);
            if(c=='L') h.push_back(-1);
            if(c=='R') h.push_back(1);
        }
        cout << opt(n,v) << " " << opt(m,h) << "\n";
    }
    return 0;
}