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
        vector<array<int,2>> v(n+1,{0,0});
        for(int i=1;i<=n;i++) cin >> v[i][0] >> v[i][1];
        sort(v.begin(),v.end());
        vector<int> cnt(n+1,0);
        for(int i=1;i<=n;i++) cnt[v[i][1]]++;
        ll bad=0;
        int l=1;
        while(l<=n)
        {
            int r=l;
            while(r+1<=n&&v[r+1][0]==v[l][0]) r++;
            for(int i=l;i<=r;i++) cnt[v[i][1]]--;
            for(int i=l;i<=r;i++) bad+=(ll(cnt[v[i][1]])*(r-l));
            for(int i=l;i<=r;i++) cnt[v[i][1]]++;
            l=r+1;
        }
        cout << ll(n)*(n-1)*(n-2)/6-bad << "\n";
    }
    return 0;
}