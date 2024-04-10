#include <vector>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <iomanip>
using namespace std;

const bool kFileInput = false;
const bool kDebugOutput = false;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    if (kFileInput) {
        freopen("input.txt", "r", stdin);
    }

    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        --p[i];
    }

    for (int i = 0; i < n; ++i) {
        if (i == p[i]) {
            cout << "YES" << endl;
            for (int j = 0; j < n; ++j) {
                if (j != i) {
                    cout << i + 1 << " " << j + 1 << endl;
                }
            }
            return 0;
        }
    }

    vector<vector<int> > cycles;
    vector<bool> used(n, false);
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            cycles.push_back(vector<int>());
            cycles.back().push_back(i);
            for (int j = p[i]; j != i; j = p[j]) {
                cycles.back().push_back(j);
            }
            for (auto x: cycles.back()) {
                used[x] = true;
            }
        }
    }

    int head = -1;
    for (int i = 0; i < (int) cycles.size(); ++i) {
        if (cycles[i].size() == 2) {
            head = i;
            break;
        }
    }

    if (head == -1) {
        cout << "NO" << endl;
        return 0;
    }

    for (int i = 0; i < (int) cycles.size(); ++i) {
        if (cycles[i].size() & 1) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    cout << cycles[head][0] + 1 << " " << cycles[head][1] + 1 << endl;
    for (int i = 0; i < (int) cycles.size(); ++i) {
        if (i != head) {
            for (int j = 0; j < (int) cycles[i].size(); ++j) {
                if (j & 1) {
                    cout << cycles[head][1] + 1 << " " << cycles[i][j] + 1 << endl;
                } else {
                    cout << cycles[head][0] + 1 << " " << cycles[i][j] + 1 << endl;
                }
            }
        }
    }

    return 0;
}