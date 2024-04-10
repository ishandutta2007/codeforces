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
        bool ok=0;
        char c;
        for(int i=1;i<=n-2;i++)
        {
            string s;
            cin >> s;
            if(i==1) cout << s[0];
            else if(c!=s[0])
            {
                cout << s[0];
                ok=1;
            }
            cout << s[1];
            c=s[1];
            if(i==n-2&&ok==0) cout << "a";
        }
        cout << "\n";
    }
    return 0;
}