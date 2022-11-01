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
        vector<int> a(n,0);
        for(int i=0;i<n;i++) cin >> a[i];
        array<int,2> c={0,0};
        for(int i=0;i<n;i++)
        {
            if(a[i]!=a[n-1-i])
            {
                c={a[i],a[n-1-i]};
                break;
            }
        }
        auto go=[&](int x)->bool
        {
            vector<int> b;
            for(int i=0;i<n;i++) if(a[i]!=x) b.push_back(a[i]);
            int m=b.size();
            for(int i=0;i<m;i++) if(b[i]!=b[m-1-i]) return 0;
            return 1;
        };
        if(go(c[0])||go(c[1])) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}