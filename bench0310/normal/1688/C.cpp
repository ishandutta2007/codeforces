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
        for(int i=1;i<=2*n+1;i++)
        {
            string s;
            cin >> s;
            for(char a:s) c[a-'a']^=1;
        }
        for(int i=0;i<26;i++) if(c[i]==1) cout << char('a'+i) << "\n";
    }
    return 0;
}