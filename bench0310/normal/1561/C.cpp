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
        for(int i=0;i<n;i++)
        {
            int k;
            cin >> k;
            vector<int> a(k);
            for(int j=0;j<k;j++)
            {
                cin >> a[j];
                a[j]++;
            }
            int r=a[k-1];
            for(int j=k-2;j>=0;j--) r=max(a[j],r-1);
            v[i]={r,k};
        }
        sort(v.begin(),v.end());
        int res=0;
        int now=0;
        for(auto [r,x]:v)
        {
            int y=max(0,r-now);
            res+=y;
            now+=(y+x);
        }
        cout << res << "\n";
    }
    return 0;
}