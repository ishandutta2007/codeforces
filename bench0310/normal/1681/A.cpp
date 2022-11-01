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
        auto r=[&]()->int
        {
            int n;
            cin >> n;
            int m=0;
            for(int i=1;i<=n;i++)
            {
                int a;
                cin >> a;
                m=max(m,a);
            }
            return m;
        };
        int ma=r();
        int mb=r();
        if(ma>=mb) cout << "Alice\n";
        else cout << "Bob\n";
        if(mb>=ma) cout << "Bob\n";
        else cout << "Alice\n";
    }
    return 0;
}