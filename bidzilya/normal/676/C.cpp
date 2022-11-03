#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool Check(int len, const string& s, int n, int k) {
    int count[2];
    count[0] = count[1] = 0;
    auto check = [&] () {
        int maxCount = max(count[0], count[1]);
        if (len - maxCount <= k) {
            return true;
        } else {
            return false;
        }
    };
    for (int i = 0; i < len; ++i) {
        ++count[s[i] - 'a'];
    }
    if (check()) {
        return true;
    }
    for (int i = len; i < n; ++i) {
        ++count[s[i] - 'a'];
        --count[s[i - len] - 'a'];
        if (check()) {
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int bl = 0;
    int br = n;
    int ba = 0;
    while (bl <= br) {
        int bm = (bl + br) >> 1;

        if (Check(bm, s, n, k)) {
            ba = bm;
            bl = bm + 1;
        } else {
            br = bm - 1;
        }
    }

    cout << ba << endl;

    return 0;
}