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
        string a=s;
        sort(a.begin(),a.end());
        int res=0;
        for(int i=0;i<n;i++) res+=(a[i]!=s[i]);
        cout << res << "\n";
    }
    return 0;
}