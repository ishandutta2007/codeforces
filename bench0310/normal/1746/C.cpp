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
        vector<int> a(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        vector<array<int,2>> v;
        for(int i=1;i<n;i++) if(a[i]>a[i+1]) v.push_back({a[i]-a[i+1],i+1});
        ranges::sort(v,greater<>());
        vector<int> res(n+1,1);
        int p=n;
        for(int i=0;i<(int)v.size();i++)
        {
            res[p--]=v[i][1];
        }
        for(int i=1;i<=n;i++) cout << res[i] << " \n"[i==n];
    }
    return 0;
}