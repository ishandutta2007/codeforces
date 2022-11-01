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
        vector<int> c(26,0);
        for(int i=0;i<n;i++) c[s[i]-'a']=1;
        int cnt=0;
        for(int i=0;i<26;i++) cnt+=c[i];
        bool ok=1;
        for(int i=0;i+cnt<n;i++) ok&=(s[i]==s[i+cnt]);
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}