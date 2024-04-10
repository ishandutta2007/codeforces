#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int CHARS_COUNT = 26;

inline int GetChar(char c) {
    return c - 'a';
}

int n, m, k;

vector<string> a;

struct TBox {
    pair<int, int> UpperLeft;
    pair<int, int> LowerRight;
    char Value;
};

vector<TBox> boxes;

struct TEvent {
    int Sign;
    int From;
    int To;
    int Pos;
    int Value;
};

void Solve() {
    vector<TEvent> events;
    for (int i = 0; i < k; ++i) {
        events.push_back(
            TEvent{1,
                boxes[i].UpperLeft.second, boxes[i].LowerRight.second,
                boxes[i].UpperLeft.first, GetChar(boxes[i].Value)});
        events.push_back(
            TEvent{-1,
                boxes[i].UpperLeft.second, boxes[i].LowerRight.second,
                boxes[i].LowerRight.first + 1, GetChar(boxes[i].Value)});
    }

    sort(events.begin(), events.end(), [] (const TEvent& lhs, const TEvent& rhs) {
        return lhs.Pos < rhs.Pos;
    });

    vector<long long> origSums(m);
    vector<vector<long long>> exSums(m, vector<long long>(CHARS_COUNT, 0));

    vector<long long> result(k, 0);

    origSums[0] += k;

    vector<vector<long long>> cur(m, vector<long long>(CHARS_COUNT, 0));
    vector<long long> origDiff(m);
    vector<vector<long long>> exDiff(m, vector<long long>(CHARS_COUNT, 0));

    for (int i = 0, ptr = 0; i < n; ++i) {
        while (ptr < (int) events.size() && events[ptr].Pos == i) {
            const TEvent& e = events[ptr++];
            origSums[e.From] -= e.Sign;
            exSums[e.From][e.Value] += e.Sign;
            if (e.To + 1 < m) {
                origSums[e.To + 1] += e.Sign;
                exSums[e.To + 1][e.Value] -= e.Sign;
            }
        }

        for (int j = 0; j < m; ++j) {
            for (int c = 0; c < CHARS_COUNT; ++c) {
                cur[j][c] = (j == 0 ? 0 : cur[j - 1][c]);
                cur[j][c] += exSums[j][c];
            }
        }

        {
            long long orig = 0;
            for (int j = 0; j < m; ++j) {
                orig += origSums[j];
                cur[j][GetChar(a[i][j])] += orig;
            }
        }

        for (int j = 0; j < m; ++j) {
            origDiff[j] = (j == 0 ? 0 : origDiff[j - 1]);
            for (int c = 0; c < CHARS_COUNT; ++c) {
                exDiff[j][c] = (j == 0 ? 0 : exDiff[j - 1][c]);
            }

            long long beforeCount = 0;
            long long beforeSum = 0;
            long long afterCount = 0;
            long long afterSum = 0;
            for (int c = 0; c < CHARS_COUNT; ++c) {
                afterSum += cur[j][c] * c;
                afterCount += cur[j][c];
            }

            for (int c = 0; c < CHARS_COUNT; ++c) {
                afterCount -= cur[j][c];
                beforeCount += cur[j][c];

                afterSum -= cur[j][c] * c;
                beforeSum += cur[j][c] * c;

                const long long curDiff = afterSum - afterCount * c +
                    beforeCount * c - beforeSum;

                if (c == GetChar(a[i][j])) {
                    origDiff[j] += curDiff;
                }

                exDiff[j][c] += curDiff;
            }
        }

        for (int id = 0; id < k; ++id) {
            if (i >= boxes[id].UpperLeft.first && i <= boxes[id].LowerRight.first) {
                int l = boxes[id].UpperLeft.second;
                int r = boxes[id].LowerRight.second;

                if (l > 0) {
                    result[id] += origDiff[l - 1];
                }

                if (r != m - 1) {
                    result[id] += origDiff[m - 1];
                    result[id] -= origDiff[r];
                }

                result[id] += exDiff[r][GetChar(boxes[id].Value)];

                if (l > 0) {
                    result[id] -= exDiff[l - 1][GetChar(boxes[id].Value)];
                }
            } else {
                result[id] += origDiff[m - 1];
            }
        }
    }

    long long glResult = result[0];
    for (int i = 1; i < k; ++i) {
        glResult = min(glResult, result[i]);
    }

    cout << glResult << endl;
}

bool Read() {
    if (scanf("%d %d %d\n", &n, &m, &k) == EOF) {
        return false;
    }
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        a[i].resize(m);
        for (int j = 0; j < m; ++j) {
            scanf("%c", &a[i][j]);
        }
        scanf("\n");
    }
    boxes.resize(k);
    for (int i = 0; i < k; ++i) {
        scanf("%d %d %d %d %c\n", &boxes[i].UpperLeft.first, &boxes[i].UpperLeft.second,
            &boxes[i].LowerRight.first, &boxes[i].LowerRight.second, &boxes[i].Value);

        --boxes[i].UpperLeft.first;
        --boxes[i].UpperLeft.second;

        --boxes[i].LowerRight.first;
        --boxes[i].LowerRight.second;
    }
    return true;
}

int main() {
    // freopen("input.txt", "r", stdin);

    while (Read()) {
        Solve();
    }

    return 0;
}