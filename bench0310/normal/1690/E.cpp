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
        ll res=0;
        vector<int> v;
        for(int i=1;i<=n;i++)
        {
            int a;
            cin >> a;
            res+=(a/k);
            v.push_back(a%k);
        }
        ranges::sort(v);
        int l=0;
        for(int r=n-1;;r--)
        {
            while(l+1<r&&v[l]+v[r]<k) l++;
            if(l>=r) break;
            if(v[l]+v[r]>=k)
            {
                res++;
                l++;
            }
        }
        cout << res << "\n";
    }
    return 0;
}