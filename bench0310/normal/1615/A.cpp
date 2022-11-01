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
        int s=0;
        for(int i=1;i<=n;i++)
        {
            int a;
            cin >> a;
            s=(s+a)%n;
        }
        cout << (s!=0) << "\n";
    }
    return 0;
}