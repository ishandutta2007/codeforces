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
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        bool ok=(2*k<n);
        for(int i=0;i<k;i++) ok&=(s[i]==s[n-1-i]);
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}