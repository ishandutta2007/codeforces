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
        int l=n/2,r=n/2;
        while(l-1>=0&&s[l-1]==s[l]) l--;
        while(r+1<n&&s[r+1]==s[r]) r++;
        cout << r-l+1 << "\n";
    }
    return 0;
}