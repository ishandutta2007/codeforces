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
        set<char> a;
        for(char c:s) a.insert(c);
        if(a.size()==2&&s[0]!=s[n-1]) s[0]^=('a'^'b');
        cout << s << "\n";
    }
    return 0;
}