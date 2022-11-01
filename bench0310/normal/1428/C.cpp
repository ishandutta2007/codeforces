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
        stack<char> a;
        for(char c:s)
        {
            if(!a.empty()&&c=='B') a.pop();
            else a.push(c);
        }
        cout << a.size() << "\n";
    }
    return 0;
}