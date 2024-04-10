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
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=i;j++) cout << (j==1||j==i) << " \n"[j==i];
        }
    }
    return 0;
}