#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    string a="2020";
    while(t--)
    {
        int n;
        string s;
        cin >> n >> s;
        bool ok=0;
        for(int i=0;i<=4;i++) ok|=(s.substr(0,i)==a.substr(0,i)&&s.substr(s.size()-(4-i),4-i)==a.substr(4-(4-i),4-i));
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}