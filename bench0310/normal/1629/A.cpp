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
        int n,k;
        cin >> n >> k;
        vector<array<int,2>> v(n);
        for(int j=0;j<2;j++) for(int i=0;i<n;i++) cin >> v[i][j];
        ranges::sort(v);
        for(auto [a,b]:v) if(k>=a) k+=b;
        cout << k << "\n";
    }
    return 0;
}