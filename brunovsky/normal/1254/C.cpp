#include <bits/stdc++.h>

using namespace std;

// *****

#define long int64_t

long QUERY_AREA(int i, int j, int k) {
    assert(i != j && j != k && k != i);
    printf("1 %d %d %d\n", i, j, k);
    long area;
    cin >> area;
    return area;
}

int QUERY_SIGN(int i, int j, int k) {
    assert(i != j && j != k && k != i);
    printf("2 %d %d %d\n", i, j, k);
    int sign;
    cin >> sign;
    return sign;
}

int main() {
    ios::sync_with_stdio(true);
    setbuf(stdout, nullptr);
    int N;
    cin >> N;
    // Pivot on point 1. First point after point 1.

    int after = 2;
    // N - 2 queries
    for (int n = 3; n <= N; n++) {
        if (QUERY_SIGN(1, n, after) == 1) {
            after = n;
        }
    }

    // 1..after is an edge
    // N - 2 queries
    vector<long> areas(N + 1);
    for (int n = 2; n <= N; n++) {
        if (n != after) {
            areas[n] = QUERY_AREA(1, after, n);
        }
    }

    // N - 2 queries
    vector<int> by_area;
    for (int n = 2; n <= N; n++) {
        if (n != after) {
            by_area.push_back(n);
        }
    }

    sort(begin(by_area), end(by_area), [&](int u, int v) { return areas[u] < areas[v]; });

    deque<int> hull = {1, after};

    // N - 3 queries
    for (int i = 0; i < N - 3; i++) {
        int n = by_area[i];
        int m = by_area[i + 1];
        if (QUERY_SIGN(1, n, m) == 1) {
            hull.push_back(n);
        } else {
            hull.push_front(n);
        }
    }

    hull.push_back(by_area.back());
    auto it = find(begin(hull), end(hull), 1);
    rotate(begin(hull), it, end(hull));

    cout << 0 << endl;
    for (int i = 0; i < N; i++) {
        cout << hull[i] << " \n"[i + 1 == N];
    }
    return 0;
}