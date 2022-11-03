#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>

#include <cassert>
using namespace std;

const string WIN = "Win";
const string LOSE = "Lose";
const string LOOP = "Loop";

int n;
vector<int> s[2];

vector<int> result;

vector<int> forwardWinsCount;

queue<pair<int, int>> updateQueue;

void Solve() {
    result.assign(2 * n, 0);
    for (int i = 0; i < 2; ++i) {
        updateQueue.push(make_pair(0 * 2 + i, -1));
    }

    forwardWinsCount.assign(2 * n, 0);

    while (!updateQueue.empty()) {
        int v = updateQueue.front().first;
        int r = updateQueue.front().second;

        updateQueue.pop();

        if (result[v] != 0) {
            assert(result[v] == r);
            continue;
        }

        result[v] = r;

        const int pos = v / 2;
        const int step = 1 - (v % 2);
        const vector<int>& diffs = s[step];

        if (r < 0) {
            for (int diff : diffs) {
                const int npos = (pos - diff + n) % n;
                const int u = npos * 2 + step;

                if (npos == 0) {
                    continue;
                }

                updateQueue.push(make_pair(u, 1));
            }
        } else {
            assert(r > 0);
            for (int diff : diffs) {
                const int npos = (pos - diff + n) % n;
                const int u = npos * 2 + step;

                if (npos == 0) {
                    continue;
                }

                ++forwardWinsCount[u];
                if (forwardWinsCount[u] == (int) diffs.size()) {
                    updateQueue.push(make_pair(u, -1));
                }
            }
        }
    }

    for (int i = 0; i < 2; ++i) {
        for (int j = 1; j < n; ++j) {
            int idx = j * 2 + i;
            if (result[idx] == 0) {
                cout << LOOP << " ";
            } else if (result[idx] < 0) {
                cout << LOSE << " ";
            } else {
                cout << WIN << " ";
            }
        }
        cout << endl;
    }
}

bool Read() {
    if (!(cin >> n)) {
        return false;
    }
    for (int i = 0; i < 2; ++i) {
        int k;
        cin >> k;
        s[i].resize(k);
        for (int j = 0; j < k; ++j) {
            cin >> s[i][j];
        }
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