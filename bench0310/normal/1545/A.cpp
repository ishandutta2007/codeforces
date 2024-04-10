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
        vector<int> a(n);
        vector<array<int,2>> v(n);
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
            v[i]={a[i],i};
        }
        sort(v.begin(),v.end());
        int l=0;
        bool ok=1;
        while(l<n)
        {
            int r=l;
            while(r+1<n&&v[r+1][0]==v[l][0]) r++;
            array<int,2> x={0,0};
            for(int i=l;i<=r;i++) x[v[i][1]&1]++;
            array<int,2> y={0,0};
            for(int i=l;i<=r;i++) y[i&1]++;
            ok&=(x==y);
            l=r+1;
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}