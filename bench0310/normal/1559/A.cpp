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
        int a;
        cin >> a;
        for(int i=0;i<n-1;i++)
        {
            int b;
            cin >> b;
            a&=b;
        }
        cout << a << "\n";
    }
    return 0;
}