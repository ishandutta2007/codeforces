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
        int n,m;
        cin >> n >> m;
        vector<array<int,26>> v(m);
        for(int i=0;i<m;i++) v[i].fill(0);
        for(int i=0;i<n;i++)
        {
            string s;
            cin >> s;
            for(int j=0;j<m;j++) v[j][s[j]-'a']++;
        }
        for(int i=0;i<n-1;i++)
        {
            string s;
            cin >> s;
            for(int j=0;j<m;j++) v[j][s[j]-'a']--;
        }
        for(int i=0;i<m;i++) for(int j=0;j<26;j++) if(v[i][j]==1) cout << char('a'+j);
        cout << "\n";
        cout.flush();
    }
    return 0;
}