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
        for(int i=2;2*i<=n-1;i++)
        {
            if(gcd(i,n-1-i)==1)
            {
                cout << i << " " << n-1-i << " " << 1 << "\n";
                break;
            }
        }
    }
    return 0;
}