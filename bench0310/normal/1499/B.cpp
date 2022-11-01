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
        auto solve=[&](string s,int a)->bool
        {
            for(int i=0;i<(int)s.size()-1;i++) if(s[i]==s[i+1]&&(s[i]-'0')!=a) return 0;
            return 1;
        };
        string s;
        cin >> s;
        int n=s.size();
        bool ok=(solve(s,0)||solve(s,1));
        for(int i=1;i<n;i++)
        {
            string a=s.substr(0,i);
            string b=s.substr(i);
            ok|=(solve(a,0)&&solve(b,1)&&(a.back()!='1'||b[0]!='0'));
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}