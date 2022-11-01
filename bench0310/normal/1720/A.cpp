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
        ll a,b,c,d;
        cin >> a >> b >> c >> d;
        cout << [&]()->int
        {
            if(a*d==b*c) return 0;
            if(a==0||c==0) return 1;
            return 2-(((a*d)%(b*c))==0||((b*c)%(a*d))==0);
        }() << "\n";
    }
    return 0;
}