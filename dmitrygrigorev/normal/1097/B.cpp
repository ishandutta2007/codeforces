#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0; i < n; i++) cin >> v[i];
    for (int mask=0; mask < (1<<n); mask++){
        int st = 0;
        for (int i=0; i < n; i++){
            int ba = (1<<i) & mask;
            if (ba == 0) st += v[i];
            else st -= v[i];
        }
        st %= 360;
        if (st < 0) st += 360;
        if (st==0){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}