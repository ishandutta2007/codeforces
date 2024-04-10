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
        vector<string> s(n+1);
        for(int i=1;i<=n;i++) cin >> s[i];
        bool ok=[&]()->bool
        {
            set<string> two,three,half_three;
            for(int i=1;i<=n;i++)
            {
                string tmp=s[i];
                ranges::reverse(tmp);
                if(s[i]==tmp) return 1;
                if(s[i].size()==2)
                {
                    if(two.contains(tmp)) return 1;
                    if(half_three.contains(tmp)) return 1;
                    two.insert(s[i]);
                }
                if(s[i].size()==3)
                {
                    if(three.contains(tmp)) return 1;
                    if(two.contains(tmp.substr(0,2))) return 1;
                    three.insert(s[i]);
                    half_three.insert(s[i].substr(0,2));
                }
            }
            return 0;
        }();
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}