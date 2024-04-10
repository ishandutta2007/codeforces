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
        int n,x;
        ll y;
        cin >> n >> x >> y;
        int b=0;
        for(int i=1;i<=n;i++)
        {
            int a;
            cin >> a;
            b^=(a&1);
        }
        if(((x^b)&1)==(y&1)) cout << "Alice\n";
        else cout << "Bob\n";
    }
    return 0;
}