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
        int n;
        cin >> n;
        string s;
        cin >> s;
        int c=0;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]!=')') break;
            c++;
        }
        if(c>n-c) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}