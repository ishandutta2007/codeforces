#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

const int MOD = 1e9 + 7;

inline void ModSum(int& x, int y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
    if (x < 0) {
        x += MOD;
    }
}

inline int GetModSum(int x, int y) {
    ModSum(x, y);
    return x;
}

struct TRect {
    int Down;
    int Up;
    int Left;
    int Right;
};

const int INF = 2e9 + 1;

class TSegTree {
public:
    void Init(int n) {
        N = n;
        MinHeight.assign(4 * N, INF);
        Values.clear();
        Values.resize(4 * N);
    }

    void Add(int pos, int height, int value) {
        Add(1, 0, N - 1, pos, height, value);
    }

    int Fetch(int l, int r, int upperBound) {
        return Fetch(1, 0, N - 1, l, r, upperBound);
    }

private:
    int N;
    vector<int> MinHeight;
    vector<stack<pair<int, int>>> Values;

    void Add(int v, int tl, int tr, int pos, int height, int value) {
        if (tl == tr) {
            MinHeight[v] = min(MinHeight[v], height);
            Values[v].push(make_pair(height, value));
        } else {
            int tm = (tl + tr) >> 1;
            if (pos <= tm) {
                Add(2 * v, tl, tm, pos, height, value);
            } else {
                Add(2 * v + 1, tm + 1, tr, pos, height, value);
            }
            MinHeight[v] = min(MinHeight[2 * v], MinHeight[2 * v + 1]);
        }
    }

    int Fetch(int v, int tl, int tr, int l, int r, int upperBound) {
        if (MinHeight[v] > upperBound) {
            return 0;
        }
        if (tl == tr) {
            int result = 0;
            while (!Values[v].empty() && Values[v].top().first <= upperBound) {
                ModSum(result, Values[v].top().second);
                Values[v].pop();
            }
            MinHeight[v] = INF;
            if (!Values[v].empty()) {
                MinHeight[v] = Values[v].top().first;
            }
            return result;
        } else {
            int tm = (tl + tr) >> 1;
            int result = 0;
            if (r <= tm) {
                result = Fetch(2 * v, tl, tm, l, r, upperBound);
            } else if (l > tm) {
                result = Fetch(2 * v + 1, tm + 1, tr, l, r, upperBound);
            } else {
                result = GetModSum(
                    Fetch(2 * v, tl, tm, l, tm, upperBound),
                    Fetch(2 * v + 1, tm + 1, tr, tm + 1, r, upperBound)
                );
            }
            MinHeight[v] = min(MinHeight[2 * v], MinHeight[2 * v + 1]);
            return result;
        }
    }
};

int h, w, n;
vector<TRect> rects;
TSegTree tree;

void Solve() {
    sort(rects.begin(), rects.end(), [] (const TRect& lhs, const TRect& rhs) {
        return lhs.Down > rhs.Down;
    });
    tree.Init(w);
    for (int i = 0; i < w; ++i) {
        tree.Add(i, h + 1, 1);
    }
    for (const auto& rect : rects) {
        const auto value = tree.Fetch(rect.Left, rect.Right, rect.Up);
        if (rect.Left != 0 && rect.Right != w - 1) {
            tree.Add(rect.Left - 1, rect.Down, value);
            tree.Add(rect.Right + 1, rect.Down, value);
        } else if (rect.Left != 0) {
            tree.Add(rect.Left - 1, rect.Down, GetModSum(value, value));
        } else {
            tree.Add(rect.Right + 1, rect.Down, GetModSum(value, value));
        }
    }
    cout << tree.Fetch(0, w - 1, INF) << endl;
}

bool Read() {
    if (!(cin >> h >> w >> n)) {
        return false;
    }
    rects.resize(n);
    for (int i = 0; i < n; ++i) {
        int u, l, r, s;
        cin >> u >> l >> r >> s;
        rects[i].Down = u;
        rects[i].Up = u + s;
        rects[i].Left = l - 1;
        rects[i].Right = r - 1;
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