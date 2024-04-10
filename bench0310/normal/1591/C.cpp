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
        int n,k;
        cin >> n >> k;
        vector<int> a,b;
        for(int i=1;i<=n;i++)
        {
            int x;
            cin >> x;
            if(x>0) a.push_back(x);
            if(x<0) b.push_back(-x);
        }
        ll sum=0;
        int mx=0;
        for(auto v:{a,b})
        {
            ranges::sort(v);
            int sz=v.size();
            for(int i=sz-1;i>=0;i-=k)
            {
                sum+=v[i];
                mx=max(mx,v[i]);
            }
        }
        cout << 2*sum-mx << "\n";
    }
    return 0;
}