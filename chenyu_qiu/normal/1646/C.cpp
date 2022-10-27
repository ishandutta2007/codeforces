#include <bits/stdc++.h>

using namespace std;
using LL = long long;
LL jc[15];
LL sum[40000];

LL lowbit(LL x) {
    return x & -x;
}

int getbit(LL x) {
    int ans = 0;
    while (x) {
        ans++;
        x -= lowbit(x);
    }
    return ans;
}

int getlowpos(LL x) {
    LL low = lowbit(x);
    int tot = 0;
    while (low) {
        if (low == (1 << tot))break;
        ++tot;
    }
    return tot;
}

int main() {
    int T;
    cin >> T;
    jc[0] = 1;
    for (int i = 1; i < 15; i++)jc[i] = jc[i - 1] * i;
    for (int i = 1; i < (1LL << 15); i++) {
        sum[i] = sum[i - lowbit(i)] + jc[getlowpos(i)];
    }

    while (T--) {
        LL n;
        cin >> n;
        int ans = 1e9 + 7;
        for (int aim = 0; aim < (1LL << 15); aim++) {
            if (n < sum[aim])continue;
//            clog << "aim " << aim << endl;
            int x = getbit(n - sum[aim]);
//            clog << "x " << x << endl;
            int y = getbit(aim);
//            clog << "y " << y << endl;
            ans = min(ans, x + y);
//            clog << "ans " << ans << endl;
        }
        cout << ans << endl;
    }
    return 0;
}