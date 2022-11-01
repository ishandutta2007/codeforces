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
        int a=0;
        for(char c:s) a+=(c=='N');
        if(a!=1) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}