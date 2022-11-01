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
        auto go=[&]()
        {
            int c=0;
            for(char x:s)
            {
                c+=(x=='T'?1:-1);
                ok&=(c>=0);
            }
            ok&=(c==n/3);
        };
        go();
        reverse(s.begin(),s.end());
        go();
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}