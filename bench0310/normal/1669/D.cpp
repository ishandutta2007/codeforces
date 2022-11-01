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
        string s;
        cin >> s;
        bool ok=1;
        int l=0;
        while(l<n)
        {
            if(s[l]=='W')
            {
                l++;
                continue;
            }
            int r=l;
            while(r+1<n&&s[r+1]!='W') r++;
            set<char> tmp;
            for(int i=l;i<=r;i++) tmp.insert(s[i]);
            ok&=(tmp.size()==2);
            l=r+1;
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}