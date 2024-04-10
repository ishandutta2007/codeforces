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
        array<int,3> x;
        cin >> x[0] >> x[1] >> x[2];
        bool ok=0;
        for(int o=0;o<3;o++)
        {
            auto [a,b,c]=x;
            if(b==c&&(a%2)==0) ok=1;
            if(b!=c&&b+c==a) ok=1;
            ranges::rotate(x,x.begin()+1);
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}