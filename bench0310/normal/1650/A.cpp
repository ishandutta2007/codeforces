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
        char c;
        cin >> s >> c;
        string tmp;
        for(int i=0;i<(int)s.size();i+=2) tmp+=s[i];
        if(tmp.find(c)!=-1) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}