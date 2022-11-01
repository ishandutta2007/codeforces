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
        for(int i=0;i+1<n;i++) c+=(s[i]!=s[i+1]);
        cout << max(0,c+(s[0]=='1')-1) << "\n";
    }
    return 0;
}