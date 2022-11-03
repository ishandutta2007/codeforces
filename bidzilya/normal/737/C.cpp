#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n, s;
vector<int> a;

void Solve() {
    bool firstGood = (a[s] == 0);
    if (n == 1) {
        if (firstGood) {
            cout << 0 << endl;
        } else {
            cout << 1 << endl;
        }
        return;
    }
    {
        vector<int> b;
        for (int i = 0; i < n; ++i) {
            if (a[i] != 0 && i != s) {
                b.push_back(a[i]);
            }
        }
        a = b;
    }
    int addResult = n - (int) a.size() - firstGood;
    int addCount = n - (int) a.size() - 1;

    vector<int> holes(n);
    vector<int> ours(n);
    for (int i = 0; i < (int) a.size(); ++i) {
        ++ours[a[i]];
    }
    for (int i = 1; i < n; ++i) {
        if (!ours[i]) {
            holes[i] = 1;
        }
    }
    for (int i = 2; i < n; ++i) {
        ours[i] += ours[i - 1];
        holes[i] += holes[i - 1];
    }
    int result = n;
    for (int i = 1; i < n; ++i) {
        int bads = (int) a.size() - ours[i];
        int curCount = addCount + bads;
        int needCount = holes[i];
        int curResult = addResult + bads;
        if (curCount < needCount) {
            curResult += (needCount - curCount);
        }
        result = min(result, curResult);
    }
    cout << result << endl;
}

bool Read() {
    if (!(cin >> n >> s)) {
        return false;
    }
    --s;
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