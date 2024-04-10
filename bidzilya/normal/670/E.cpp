#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

struct TSegmentTree {

    void Init(int n) {
        N = n;
        Left.resize(4 * n);
        Right.resize(4 * n);
        Value.resize(4 * n);
        Push.resize(4 * n);
        Build(1, 0, n - 1);
    }

    int FindLeft(int l, int r) {
        return FindLeft(1, 0, N - 1, l, r);
    }

    int FindLeft(int v, int tl, int tr, int l, int r) {
        DoPush(v, tl, tr);
        if (tl == l && tr == r) {
            return Left[v];
        } else {
            int tm = (tl + tr) >> 1;
            if (r <= tm) {
                return FindLeft(2 * v, tl, tm, l, r);
            } else if (l > tm) {
                return FindLeft(2 * v + 1, tm + 1, tr, l, r);
            } else {
                int valLeft = FindLeft(2 * v, tl, tm, l, tm);
                int valRight = FindLeft(2 * v + 1, tm + 1, tr, tm + 1, r);
                if (valLeft != -1) {
                    return valLeft;
                } else {
                    return valRight;
                }
            }
        }
    }

    int FindRight(int l, int r) {
        return FindRight(1, 0, N - 1, l, r);
    }

    int FindRight(int v, int tl, int tr, int l, int r) {
        DoPush(v, tl, tr);
        if (tl == l && tr == r) {
            return Right[v];
        } else {
            int tm = (tl + tr) >> 1;
            if (r <= tm) {
                return FindRight(2 * v, tl, tm, l, r);
            } else if (l > tm) {
                return FindRight(2 * v + 1, tm + 1, tr, l, r);
            } else {
                int valLeft = FindRight(2 * v, tl, tm, l, tm);
                int valRight = FindRight(2 * v + 1, tm + 1, tr, tm + 1, r);
                if (valRight != -1) {
                    return valRight;
                } else {
                    return valLeft;
                }
            }
        }
    }

    void DoPush(int l, int r) {
        DoPush(1, 0, N - 1, l, r);
    }

    void DoPush(int v, int tl, int tr, int l, int r) {
        DoPush(v, tl, tr);
        if (tl == l && tr == r) {
            Push[v] = 1;
            Left[v] = Right[v] = -1;
            Value[v] = 0;
        } else {
            int tm = (tl + tr) >> 1;
            if (r <= tm) {
                DoPush(2 * v, tl, tm, l, r);
            } else if (l > tm) {
                DoPush(2 * v + 1, tm + 1, tr, l, r);
            } else {
                DoPush(2 * v, tl, tm, l, tm);
                DoPush(2 * v + 1, tm + 1, tr, tm + 1, r);
            }
            if (Left[2 * v] != -1) {
                Left[v] = Left[2 * v];
            } else {
                Left[v] = Left[2 * v + 1];
            }
            if (Right[2 * v + 1] != -1) {
                Right[v] = Right[2 * v + 1];
            } else {
                Right[v] = Right[2 * v];
            }
        }
    }

    void Build(int v, int tl, int tr) {
        Push[v] = 0;
        if (tl == tr) {
            Value[v] = 1;
            Left[v] = tl;
            Right[v] = tl;
        } else {
            int tm = (tl + tr) >> 1;
            Build(2 * v, tl, tm);
            Build(2 * v + 1, tm + 1, tr);
            Left[v] = tl;
            Right[v] = tr;
            Value[v] = 0;
        }
    }

    void DoPush(int v, int tl, int tr) {
        if (Push[v] == 1) {
            Push[v] = 0;
            if (tl != tr) {
                Push[2 * v] = Push[2 * v + 1] = 1;
                Left[2 * v] = Left[2 * v + 1] = Right[2 * v] = Right[2 * v + 1] = -1;
                Value[2 * v] = Value[2 * v + 1] = 0;
            }
        }
    }

    void Fill(vector<int>& value) {
        Fill(1, 0, N - 1, value);
    }

    void Fill(int v, int tl, int tr, vector<int>& value) {
        DoPush(v, tl, tr);
        if (tl == tr) {
            value[tl] = Value[v];
        } else {
            int tm = (tl + tr) >> 1;
            Fill(2 * v, tl, tm, value);
            Fill(2 * v + 1, tm + 1, tr, value);
        }
    }

    int N;
    vector<int> Left;
    vector<int> Right;
    vector<int> Value;
    vector<int> Push;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, p;
    cin >> n >> m >> p;
    --p;

    string s;
    cin >> s;

    string op;
    cin >> op;

    TSegmentTree seg;
    seg.Init(n);

    vector<int> to(n);

    stack<int> st;
    for (int i = 0; i < n; ++i) {
        if (st.empty()) {
            st.push(i);
        } else {
            if (s[i] == '(') {
                st.push(i);
            } else {
                to[i] = st.top();
                to[st.top()] = i;
                st.pop();
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        if (op[i] == 'L') {
            p = seg.FindRight(0, p - 1);
        } else if (op[i] == 'R') {
            p = seg.FindLeft(p + 1, n - 1);
        } else {
            int l = min(to[p], p);
            int r = max(to[p], p);
            seg.DoPush(l, r);
            int right = -1;
            if (r + 1 <= n - 1) {
                right = seg.FindLeft(r + 1, n - 1);
            }
            if (right == -1) {
                p = seg.FindRight(0, l - 1);
            } else {
                p = right;
            }
        }
    }

    vector<int> value(n);
    seg.Fill(value);

    for (int i = 0; i < n; ++i) {
        if (value[i]) {
            cout << s[i];
        }
    }
    cout << endl;

    return 0;
}