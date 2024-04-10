#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    cout << "YES\n";
    while(n--)
    {
        int x,y,z;
        cin >> x >> y >> z >> z;
        cout << (2*(x&1)+(y&1))+1 << "\n";
    }
    return 0;
}