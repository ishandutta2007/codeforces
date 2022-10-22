#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        int m = 1;
        while(n > 0)
        {
            m = max(m, n%10);
            n /= 10;
        }
        cout << m << "\n";
    }
}