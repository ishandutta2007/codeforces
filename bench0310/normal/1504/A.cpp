#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    auto pal=[](string s)->bool
    {
        int n=s.size();
        for(int i=0;i<n;i++) if(s[i]!=s[n-1-i]) return 0;
        return 1;
    };
    while(t--)
    {
        string s;
        cin >> s;
        if(pal("a"+s)==0) cout << "YES\n" << "a" << s << "\n";
        else if(pal(s+"a")==0) cout << "YES\n" << s << "a" << "\n";
        else cout << "NO\n";
    }
    return 0;
}