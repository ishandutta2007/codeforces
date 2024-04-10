#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include <cassert>
using namespace std;

const int INF = 1e9;

const vector<int> SCORES = {
    3000, 2500, 2000, 1500, 1000, 500};

const vector<int> LS = {
    0, 1, 1, 1, 1, 1, 1};

const vector<int> RS = {
    1, 32, 16, 8, 4, 2, 1};

const int TC = 5;

const int MAX_BOTS_COUNT = 4000;

int n;
vector<int> a[TC];
int counter[TC];

bool IsOk(int taskId, int scoreId, int botsCount, bool solvedByVasya) {
    if (scoreId == 0) {
        if (counter[taskId] == 0) {
            return true;
        }
    }
    const int a = LS[scoreId];
    const int b = RS[scoreId];
    const int c = LS[scoreId + 1];
    const int d = RS[scoreId + 1];
    const int p = counter[taskId];
    const int q = n;
    int minP = 0;
    int maxP = (solvedByVasya ? botsCount : 0);
    {
        const int up = c * q + c * botsCount - p * d;
        const int down = d;
        if (up < 0) {
            return false;
        }
        int cp = up / down;
        while (cp * down > up) {
            --cp;
        }
        while ((cp + 1) * down <= up) {
            ++cp;
        }
        maxP = min(maxP, cp);
    }
    {
        const int up = a * q + a * botsCount - p * b;
        const int down = b;
        if (up >= 0) {
            int cp = up / down;
            while (cp * down <= up) {
                ++cp;
            }
            while ((cp - 1) * down > up) {
                --cp;
            }
            minP = max(minP, cp);
        }
    }
    return minP <= maxP;
}

int GetScore(int playerId, int taskId, int scoreId) {
    if (a[taskId][playerId] == -1) {
        return 0;
    }
    const int fullScore = SCORES[scoreId];
    return fullScore - fullScore / 250 * a[taskId][playerId];
}

int GetScore(int taskId, int scoreId) {
    return GetScore(0, taskId, scoreId) - GetScore(1, taskId, scoreId);
}

void Solve() {
    for (int i = 0; i < TC; ++i) {
        counter[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < TC; ++j) {
            if (a[j][i] != -1) {
                ++counter[j];
            }
        }
    }
    for (int botsCount = 0; botsCount < MAX_BOTS_COUNT; ++botsCount) {
        int maxScore = 0;
        for (int taskId = 0; taskId < TC; ++taskId) {
            int curMaxScore = -INF;
            for (int scoreId = 0; scoreId < (int) SCORES.size(); ++scoreId) {
                if (IsOk(taskId, scoreId, botsCount, a[taskId][0] != -1)) {
                    curMaxScore = max(curMaxScore, GetScore(taskId, scoreId));
                }
            }

            assert(curMaxScore != -INF);

            maxScore += curMaxScore;
        }
        if (maxScore > 0) {
            cout << botsCount << endl;
            return;
        }
    }
    cout << -1 << endl;
}

bool Read() {
    if (!(cin >> n)) {
        return false;
    }
    for (int i = 0; i < TC; ++i) {
        a[i].resize(n);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < TC; ++j) {
            cin >> a[j][i];
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