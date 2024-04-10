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
        int q,d;
        cin >> q >> d;
        while(q--)
        {
            int a;
            cin >> a;
            bool ok=0;
            auto ch=[&](int x)->bool
            {
                return (a-x>=0&&((a-x)%d)==0);
            };
            for(int i=0;i<=9;i++) ok|=ch(10*i+d);
            for(int i=0;i<=9;i++) ok|=ch(10*d+i);
            if(ok) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}