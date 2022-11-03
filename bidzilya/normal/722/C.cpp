#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class TSegTree {
public:
    void Init(const vector<int>& a) {
        N = a.size();
        MaxSum.resize(4 * N);
        LeftSum.resize(4 * N);
        RightSum.resize(4 * N);
        DelCount.resize(4 * N);
        Build(1, 0, N - 1, a);
    }

    long long Get() const {
        return MaxSum[1];
    }

    void Del(int pos) {
        Del(1, 0, N - 1, pos);
    }

private:
    int N;
    vector<long long> MaxSum;
    vector<long long> LeftSum;
    vector<long long> RightSum;
    vector<int> DelCount;

    void Build(int v, int tl, int tr, const vector<int>& a) {
        DelCount[v] = 0;
        if (tl == tr) {
            MaxSum[v] = a[tl];
            LeftSum[v] = a[tl];
            RightSum[v] = a[tl];
        } else {
            int tm = (tl + tr) >> 1;

            Build(2 * v, tl, tm, a);
            Build(2 * v + 1, tm + 1, tr, a);

            Merge(v, tl, tr);
        }
    }

    void Del(int v, int tl, int tr, int pos) {
        if (tl == tr) {
            DelCount[v] = 1;
            MaxSum[v] = LeftSum[v] = RightSum[v] = 0;
        } else {
            int tm = (tl + tr) >> 1;

            if (pos <= tm) {
                Del(2 * v, tl, tm, pos);
            } else {
                Del(2 * v + 1, tm + 1, tr, pos);
            }

            Merge(v, tl, tr);
        }
    }

    void Merge(int v, int tl, int tr) {
        if (tl == tr) {
            return;
        }

        DelCount[v] = DelCount[2 * v] + DelCount[2 * v + 1];

        LeftSum[v] = LeftSum[2 * v];
        if (DelCount[2 * v] == 0) {
            LeftSum[v] = max(LeftSum[v], LeftSum[2 * v] + LeftSum[2 * v + 1]);
        }

        RightSum[v] = RightSum[2 * v + 1];
        if (DelCount[2 * v + 1] == 0) {
            RightSum[v] = max(RightSum[v], RightSum[2 * v + 1] + RightSum[2 * v]);
        }

        MaxSum[v] = max(MaxSum[2 * v], MaxSum[2 * v + 1]);
        MaxSum[v] = max(MaxSum[v], RightSum[2 * v] + LeftSum[2 * v + 1]);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    TSegTree st;
    st.Init(a);

    for (int i = 0; i < n; ++i) {
        int p;
        cin >> p;
        --p;

        st.Del(p);

        cout << st.Get() << '\n';
    }
    cout.flush();

    return 0;
}