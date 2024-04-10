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
        int n=s.size();
        int p=[&]()->int
        {
            for(int i=n-2;i>=0;i--) if((s[i]-'0')+(s[i+1]-'0')>=10) return i;
            return 0;
        }();
        string res;
        for(int j=0;j<p;j++) res+=s[j];
        res+=to_string(s[p]-'0'+s[p+1]-'0');
        for(int j=p+2;j<n;j++) res+=s[j];
        cout << res << "\n";
    }
    return 0;
}