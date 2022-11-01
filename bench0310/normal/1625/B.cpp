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
        vector<array<int,2>> a(n);
        for(int i=0;i<n;i++)
        {
            cin >> a[i][0];
            a[i][1]=i+1;
        }
        ranges::sort(a);
        int l=0;
        int res=-1;
        while(l<n)
        {
            int r=l;
            while(r+1<n&&a[r+1][0]==a[l][0]) r++;
            vector<int> p;
            for(int i=l;i<=r;i++) p.push_back(a[i][1]);
            for(int j=0;j+1<(int)p.size();j++)
            {
                int x=p[j];
                int y=p[j+1];
                res=max(res,x+n-y);
            }
            l=r+1;
        }
        cout << res << "\n";
    }
    return 0;
}