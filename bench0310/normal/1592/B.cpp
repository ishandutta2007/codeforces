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
        int n,x;
        cin >> n >> x;
        vector<int> a(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        int l=n-x+1,r=1+x-1;
        bool res=0;
        if(l>r) res=1;
        else
        {
            vector<int> b,c;
            for(int i=1;i<=n;i++)
            {
                if(i<l||i>r)
                {
                    b.push_back(a[i]);
                    c.push_back(i);
                }
            }
            sort(b.begin(),b.end());
            for(int i=0;i<(int)b.size();i++) a[c[i]]=b[i];
            bool ok=1;
            for(int i=1;i<n;i++) ok&=(a[i]<=a[i+1]);
            res=ok;
        }
        if(res) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}