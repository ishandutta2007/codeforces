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
        bool inc=1;
        int a=0;
        for(int i=1;i<=n;i++)
        {
            int b;
            cin >> b;
            inc&=(a<b);
            a=b;
        }
        if((n%2)==0||inc==0) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}