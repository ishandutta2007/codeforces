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
        string s;
        cin >> n >> s;
        bool ok=1;
        vector<int> v[26];
        for(int i=0;i<n;i++) v[s[i]-'A'].push_back(i);
        for(int i=0;i<26;i++) for(int j=0;j<(int)v[i].size()-1;j++) ok&=(v[i][j]+1==v[i][j+1]);
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}