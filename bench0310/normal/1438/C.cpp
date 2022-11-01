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
        int n,m;
        cin >> n >> m;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                int a;
                cin >> a;
                if((i+j)&1) cout << a+(a&1) << " ";
                else cout << a+((a%2)==0) << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}