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
        int a=(n+3)/4;
        for(int i=0;i<n-a;i++) cout << 9;
        for(int i=0;i<a;i++) cout << 8;
        cout << "\n";
    }
    return 0;
}