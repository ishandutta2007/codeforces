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
        for(int i=1;i<=n;i++)
        {
            int a;
            cin >> a;
            v[i-1]={a,i};
        }
        sort(v.begin(),v.end());
        int l=0;
        ll res=0;
        while(l<n)
        {
            int r=l;
            while(r+1<n&&v[r+1][0]==v[l][0]) r++;
            ll s=0;
            for(int i=l;i<=r;i++) s+=(n-v[i][1]+1);
            for(int i=l;i<=r;i++)
            {
                s-=(n-v[i][1]+1);
                res+=(v[i][1]*s);
            }
            l=r+1;
        }
        cout << res << "\n";
    }
    return 0;
}