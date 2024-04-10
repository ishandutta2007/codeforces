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
        string s;
        cin >> s;
        int n=s.size();
        bool ok=1;
        int l=0;
        while(l<n)
        {
            int r=l;
            while(r+1<n&&s[r+1]==s[l]) r++;
            ok&=(l<r);
            l=r+1;
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}