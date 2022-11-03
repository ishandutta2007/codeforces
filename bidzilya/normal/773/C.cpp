#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define remainder remainder123123

int GetCount(const vector<long long>& a, long long value) {
    int result = 0;
    for (int i = 0; i < (int) a.size(); ++i) {
        if (a[i] == value) {
            ++result;
        }
    }
    return result;
}

int n;
vector<long long> a;

vector<long long> paths;
vector<long long> remainder;

bool Check(int count) {
    remainder.clear();
    paths.assign(count, 0);
    long long nxt = 1;
    int li = 0;
    int ri = count - 1;
    for (int i = 0; i < n; ++i) {
        if (a[i] != nxt) {
            remainder.push_back(a[i]);
        } else {
            int j = i;
            while (j + 1 < n && a[j + 1] == a[i]) {
                ++j;
            }
            const int d = min(ri - li + 1, j - i + 1);
            li = ri - d + 1;
            for (int t = li; t <= ri; ++t) {
                paths[t] = nxt;
            }
            for (int t = 0; t < (j - i + 1) - d; ++t) {
                remainder.push_back(a[i]);
            }
            nxt *= 2;
            i = j;
        }
    }
    if (paths[0] == 0) {
        return false;
    }
    if (remainder.size() > paths.size()) {
        return false;
    }
    for (int i = (int) remainder.size() - 1, j = (int) paths.size() - 1; i >= 0; --i, --j) {
        if (remainder[i] >= paths[j] * 2) {
            return false;
        }
    }
    return true;
}

void Solve() {
    const int onesCount = GetCount(a, 1);
    if (onesCount == 0) {
        cout << -1 << endl;
        return;
    }
    paths.clear();
    paths.reserve(onesCount);
    remainder.clear();
    remainder.reserve(n);
    if (!Check(onesCount)) {
        cout << -1 << endl;
        return;
    }
    int bl = 1;
    int br = onesCount;
    int ba = onesCount;
    while (bl <= br) {
        int bm = (bl + br) >> 1;

        if (Check(bm)) {
            ba = bm;
            br = bm - 1;
        } else {
            bl = bm + 1;
        }
    }
    for (int i = ba; i <= onesCount; ++i) {
        cout << i << " ";
    }
    cout << endl;
}

bool Read() {
    if (!(cin >> n)) {
        return false;
    }
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    return true;
}

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (Read()) {
        Solve();
    }

    return 0;
}