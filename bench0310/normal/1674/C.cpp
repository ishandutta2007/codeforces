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
        bool a=0;
        for(char c:t) a|=(c=='a');
        if(t=="a") cout << "1\n";
        else if(!a) cout << (1ll<<(s.size())) << "\n";
        else cout << "-1\n";
    }
    return 0;
}