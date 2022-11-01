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
        int n,m=3,k=2;
        cin >> n;
        vector<int> a(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        sort(a.begin(),a.end());
        int r=1;
        auto c2=[&](ll d)->ll
        {
            return (d*(d-1)/2);
        };
        ll res=0;
        for(int l=1;l<=n;l++)
        {
            while(r+1<=n&&a[r+1]<=a[l]+k) r++;
            if(r-l>=m-1) res+=c2(r-l);
        }
        cout << res << "\n";
    }
    return 0;
}