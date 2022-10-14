#include <bits/stdc++.h>

using namespace std;

// *****

template <typename T>
struct RMQ {
    vector<vector<T>> jmp;
    RMQ() = default;
    RMQ(const vector<T>& V) : jmp(1, V) {
        for (unsigned pw = 1, k = 1; pw * 2 <= V.size(); pw *= 2, ++k) {
            jmp.emplace_back(V.size() - pw * 2 + 1);
            for (unsigned j = 0; j < jmp[k].size(); j++)
                jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
        }
    }
    T query(int a, int b) {
        assert(a < b);
        static constexpr int bits = CHAR_BIT * sizeof(int) - 1;
        int dep = bits - __builtin_clz(b - a);
        return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
    }
};

int N;
vector<int> H, B;
vector<int> height_index;
RMQ<int> rmq;

long long dfs(int L, int R, bool openL, bool openR) {
    if (L >= R)
        return 0;

    int min_height = rmq.query(L, R);
    int i = height_index[min_height];
    long long dfs_L = dfs(L, i, openL, true);
    long long dfs_R = dfs(i + 1, R, true, openR);

    if (!openL && !openR) {
        return dfs_L + B[i] + dfs_R;
    } else if (!openL && openR) {
        return max(dfs_L, dfs_L + B[i] + dfs_R);
    } else if (openL && !openR) {
        return max(dfs_L + B[i] + dfs_R, dfs_R);
    } else {
        return max(dfs_L + B[i] + dfs_R, max(dfs_L, dfs_R));
    }
}

// LEFT | .... | B[i] | .... | RIGHT

auto solve() {
    cin >> N;
    H.assign(N, {});
    B.assign(N, {});
    height_index.assign(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> H[i], H[i]--;
        height_index[H[i]] = i;
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }
    rmq = RMQ<int>(H);
    return dfs(0, N, false, false);
}

// *****

int main() {
    ios::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}