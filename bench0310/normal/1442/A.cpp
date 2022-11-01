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
        int now=1000000;
        int r=0;
        bool ok=1;
        for(int i=1;i<=n;i++)
        {
            int a;
            cin >> a;
            if(r>a) ok=0;
            a-=r;
            if(a<=now) now=a;
            else r+=(a-now);
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}