#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int n, m;
vector<int> a;

bool Check(long long t)
{
    int cm = m;
    int last_pos = 0;
    vector<int> ta(a.begin(), a.end());
    while (cm > 0 && last_pos < n) {
        long long power = t - last_pos;
        --cm;
        while (power > 0 && last_pos < n) {
            if (power >= ta[last_pos]) {
                power -= ta[last_pos];
                ++last_pos;
                --power;
            } else {
                ta[last_pos] -= power;
                power = 0;
            }
        }
    }
    return last_pos == n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    while (a.back() == 0) {
        a.pop_back();
        --n;
    }

    long long ans = 1e18;
    long long bl = 0;
    long long br = 1e18;
    while (bl <= br) {
        long long bm = (bl + br) >> 1;

        if (Check(bm)) {
            ans = bm;
            br = bm - 1;
        } else {
            bl = bm + 1;
        }
    }

    cout << ans + 1 << endl;

    return 0;
}