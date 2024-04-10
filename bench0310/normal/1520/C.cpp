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
        if(n==2)
        {
            cout << "-1\n";
            continue;
        }
        int now=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cout << now << " \n"[j==n];
                now+=2;
                if(now>n*n) now=2;
            }
        }
    }
    return 0;
}