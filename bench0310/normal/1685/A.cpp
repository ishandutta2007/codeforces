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
        for(int &x:a) cin >> x;
        ranges::sort(a);
        vector<int> res=[&]()->vector<int>
        {
            if(n&1) return {};
            vector<int> b(n);
            int p=0;
            for(int i=0;i<n;i+=2) b[i]=a[p++];
            for(int i=1;i<n;i+=2) b[i]=a[p++];
            bool ok=1;
            for(int i=1;i<n;i+=2)
            {
                int x=b[(i-1+n)%n];
                int y=b[(i+1)%n];
                ok&=(x<b[i]&&b[i]>y);
            }
            if(ok) return b;
            else return {};
        }();
        if(!res.empty())
        {
            cout << "YES\n";
            for(int i=0;i<n;i++) cout << res[i] << " \n"[i==n-1];
        }
        else cout << "NO\n";
    }
    return 0;
}