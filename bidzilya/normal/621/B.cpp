#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    const int MAX_N = 1e3;
    vector<vector<bool>> has(MAX_N, vector<bool>(MAX_N, false));
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
        --a[i].first;
        --a[i].second;
        has[a[i].first][a[i].second] = true;
    }

    const auto& isCorrect = [&] (int i, int j) {
        return i >= 0 && i < MAX_N && j >= 0 && j < MAX_N;
    };

    long long result = 0;

    vector<pair<int, int>> start;
    vector<pair<int, int>> deltas;

    for (int i = MAX_N - 1, j = 0; i >= 0; --i) {
        start.push_back(make_pair(i, j));
        deltas.push_back(make_pair(1, 1));
    }
    for (int i = 0, j = 1; j < MAX_N; ++j) {
        start.push_back(make_pair(i, j));
        deltas.push_back(make_pair(1, 1));
    }

    for (int i = 0, j = 0; j < MAX_N; ++j) {
        start.push_back(make_pair(i, j));
        deltas.push_back(make_pair(1, -1));
    }
    for (int i = 1, j = MAX_N - 1; i < MAX_N; ++i) {
        start.push_back(make_pair(i, j));
        deltas.push_back(make_pair(1, -1));
    }

    for (size_t itr = 0; itr < start.size(); ++itr) {
        int i = start[itr].first;
        int j = start[itr].second;

        int dx = deltas[itr].first;
        int dy = deltas[itr].second;

        int count = 0;
        while (isCorrect(i, j)) {
            count += has[i][j];
            i += dx;
            j += dy;
        }

        result += (1LL * count * (count - 1)) / 2;
    }

    cout << result << endl;

    return 0;
}