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
        bool res=0;
        for(int i=0;i<8;i++)
        {
            int a=0;
            bool ok=1;
            for(char c:s)
            {
                a+=((i&(1<<(c-'A')))?1:-1);
                ok&=(a>=0);
            }
            ok&=(a==0);
            res|=ok;
        }
        if(res) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}