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
        vector<int> b(n+1,0);
        for(int i=1;i<=n;i++) cin >> b[i];
        vector<int> v[n+1];
        for(int i=n-1;i>=1;i--) if(b[i]==b[i+1]) v[b[i]].push_back(i);
        vector<int> s(n+1,0);
        bool ok=1;
        int l=1;
        for(int i=1;i<=n;i++)
        {
            while(s[l]==1) l++;
            if(b[l]==a[i]) l++;
            else
            {
                while(!v[a[i]].empty()&&v[a[i]].back()<l) v[a[i]].pop_back();
                if(v[a[i]].empty()) ok=0;
                else
                {
                    int p=v[a[i]].back();
                    v[a[i]].pop_back();
                    s[p]=1;
                }
            }
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}