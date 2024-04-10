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
        vector<int> b(8,0);
        for(int i=1;i<=7;i++) cin >> b[i];
        cout << b[1] << " " << b[2] << " " << b[7]-b[1]-b[2] << "\n";
    }
    return 0;
}