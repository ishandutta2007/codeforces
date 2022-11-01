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
        char c=s[0];
        for(char a:s) c=min(c,a);
        bool b=0;
        cout << c << " ";
        for(char a:s)
        {
            if(b==0&&a==c) b=1;
            else cout << a;
        }
        cout << "\n";
    }
    return 0;
}