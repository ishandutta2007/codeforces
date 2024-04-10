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
        for(int i=0;i<6;i++) a+=((i<3?1:-1)*s[i]);
        if(a==0) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}