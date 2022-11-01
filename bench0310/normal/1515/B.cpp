#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    auto sq=[&](int a)->bool
    {
        int s=sqrt(a);
        while(s*s>a) s--;
        while((s+1)*(s+1)<=a) s++;
        return (s*s==a);
    };
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        bool ok=0;
        while(1)
        {
            if(n&1) break;
            n/=2;
            ok|=sq(n);
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}