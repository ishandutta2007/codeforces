#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

const int INF = 1e9;

int n;
vector<int> a[2];
vector<long long> sa[2];

vector<int> up;
vector<int> down;
vector<int> both;

vector<int> bothValue;
vector<pair<int, int>> upPosValue;
vector<pair<int, int>> downPosValue;

template <typename TGetSum>
void Fill(TGetSum&& getSum, vector<int>& result) {
    result.assign(n, INF);
    map<long long, int> last;
    last[0] = 0;
    for (int i = 0; i < n; ++i) {
        const auto sum = getSum(i);
        auto itr = last.find(sum);
        if (itr != last.end()) {
            result[itr->second] = min(result[itr->second], i);
        }
        last[sum] = i + 1;
    }
}

void Update(vector<int>& array, int pos, int value) {
    array[pos] = max(array[pos], value);
}

void Update(vector<pair<int, int>>& array, int pos, pair<int, int> value) {
    if (array[pos].first < value.first
        || (array[pos].first == value.first && array[pos].second > value.second))
    {
        array[pos] = value;
    }
}

template <typename TArray, typename TValue>
void Update(TArray& array, int pos, TValue value) {
    array[pos] = max(array[pos], value);
}

void UpdateLine(
    vector<pair<int, int>>& curPosValue,
    const vector<int>& cur,
    vector<pair<int, int>>& nxtPosValue,
    const vector<int>& nxt,
    int pos)
{
    const auto value = curPosValue[pos];
    if (value.first == -INF) {
        return;
    }

    Update(bothValue, value.second + 1, value.first);

    if (pos != value.second) {
        Update(curPosValue, pos + 1, value);
    }

    if (nxt[pos] != INF) {
        if (nxt[pos] < value.second) {
            Update(curPosValue, nxt[pos] + 1, make_pair(value.first + 1, value.second));
        }
        if (nxt[pos] == value.second) {
            Update(bothValue, nxt[pos] + 1, value.first + 1);
        }
        if (nxt[pos] > value.second) {
            Update(nxtPosValue, value.second + 1, make_pair(value.first + 1, nxt[pos]));
        }
    }
}

void Solve() {
    for (int i = 0; i < 2; ++i) {
        sa[i].resize(n);
        sa[i][0] = a[i][0];
        for (int j = 1; j < n; ++j) {
            sa[i][j] = sa[i][j - 1] + a[i][j];
        }
    }
    Fill([] (int idx) { return sa[0][idx]; }, up);
    Fill([] (int idx) { return sa[1][idx]; }, down);
    Fill([] (int idx) { return sa[0][idx] + sa[1][idx]; }, both);

    bothValue.assign(n + 1, 0);
    upPosValue.assign(n + 1, make_pair(-INF, INF));
    downPosValue.assign(n + 1, make_pair(-INF, INF));
    for (int i = 0; i < n; ++i) {
        Update(bothValue, i + 1, bothValue[i]);
        if (both[i] != INF) {
            Update(bothValue, both[i] + 1, bothValue[i] + 1);
        }
        if (up[i] != INF) {
            Update(upPosValue, i, make_pair(bothValue[i] + 1, up[i]));
        }
        if (down[i] != INF) {
            Update(downPosValue, i, make_pair(bothValue[i] + 1, down[i]));
        }

        UpdateLine(upPosValue, up, downPosValue, down, i);
        UpdateLine(downPosValue, down, upPosValue, up, i);
    }

    cout << bothValue[n] << endl;
}

bool Read() {
    if (!(cin >> n)) {
        return false;
    }
    for (int i = 0; i < 2; ++i) {
        a[i].resize(n);
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
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