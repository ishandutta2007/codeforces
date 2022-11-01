#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--)
    {
        string s,t;
        cin >> s >> t;
        vector<int> a(26,0);
        for(char c:t) a[c-'A']++;
        string res;
        for(int i=(int)s.size()-1;i>=0;i--)
        {
            if(a[s[i]-'A']>0)
            {
                res+=s[i];
                a[s[i]-'A']--;
            }
        }
        ranges::reverse(res);
        if(t==res) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}