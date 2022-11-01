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
        vector<array<int,2>> v(n);
        for(int j=0;j<2;j++) for(int i=0;i<n;i++) cin >> v[i][j];
        ranges::sort(v);
        int r=n-1;
        ll res=0;
        while(r>=0)
        {
            ll y=v[r][0];
            ll h=v[r][1];
            int l=r;
            while(l-1>=0&&v[l-1][0]>y-h)
            {
                l--;
                h=max(h,v[l][1]+y-v[l][0]);
            }
            res+=(h*(h+1)/2);
            r=l-1;
        }
        cout << res << "\n";
    }
    return 0;
}