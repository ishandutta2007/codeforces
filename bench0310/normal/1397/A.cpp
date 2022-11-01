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
        vector<int> c(26,0);
        for(int i=0;i<n;i++)
        {
            string s;
            cin >> s;
            for(char a:s) c[a-'a']++;
        }
        bool ok=1;
        for(int i=0;i<26;i++) ok&=((c[i]%n)==0);
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}