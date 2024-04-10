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
        int n,k1,k2;
        cin >> n >> k1 >> k2;
        int w,b;
        cin >> w >> b;
        int one=(k1+k2);
        int two=(2*n-one);
        if(2*w<=one&&2*b<=two) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}