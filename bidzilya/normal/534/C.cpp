#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    long long a;
    cin >> n >> a;
    long long s = 0;
    vector<int> d(n);
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
        s += d[i];
    }
    if (n == 1) {
        cout << d[0] - 1 << endl;
        return 0;
    }
    a -= n;
    s -= n;
    for (int i = 0; i < n; ++i) {
        long long l = 0;
        long long r = min(min((long long) d[i] - 1, a), a + d[i] - s - 2);
        
        long long b = 0;
        if (l <= r) {
            b += r - l + 1;
        }
        
        if (d[i] - 1 > a) {
            b += ((d[i] - 1) - (a + 1) + 1);
        }
        
        cout << b << " ";
    }
    cout << endl;
    
    return 0;
}