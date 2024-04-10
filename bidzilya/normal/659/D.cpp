#include <iostream>
#include <vector>
#include <utility>
#include <cassert>
using namespace std;

inline int GetSign(int x) {
    if (x > 0) {
        return 1;
    }
    if (x < 0) {
        return -1;
    }
    return 0;
}

inline pair<int, int> GetD(const pair<int, int>& s, const pair<int, int>& e) {
    return make_pair(GetSign(e.first - s.first), GetSign(e.second - s.second));
}

inline pair<int, int> GetSum(const pair<int, int>& a, const pair<int, int>& b) {
    return make_pair(a.first + b.first, a.second + b.second);
}

bool IsInside(pair<int, int> p, pair<int, int> d, vector<pair<int, int>>& a) {
    bool swapped = false;
    if (abs(d.first) != 1) {
        swapped = true;
        swap(p.first, p.second);
        swap(d.first, d.second);
        for (int i = 0; i < (int) a.size(); ++i) {
            swap(a[i].first, a[i].second);
        }
    }
    int f = 0;
    for (int i = 0; i < (int) a.size(); ++i) {
        int j = i + 1;
        if (j == (int) a.size()) {
            j = 0;
        }

        const pair<int, int> d2 = GetD(a[i], a[j]);
        if (abs(d2.first) == 1) {
            /*
            if (d.first == GetSign(a[i].first - p.first) && d.first == GetSign(a[j].first - p.first) && p.second == a[i].second) {
                ++f;
            }
            */
        } else {
            if (min(a[i].second, a[j].second) <= p.second && max(a[i].second, a[j].second) > p.second && 
                    d.first == GetSign(a[i].first - p.first)) {
                ++f;
            }
        }
    }
    if (swapped) {
        for (int i = 0; i < (int) a.size(); ++i) {
            swap(a[i].first, a[i].second);
        }
    }
    return f & 1;
}

ostream& operator << (ostream& outputStream, const pair<int, int>& a) {
    outputStream << "(" << a.first << ", " << a.second << ")";
    return outputStream;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
        a[i].first *= 2;
        a[i].second *= 2;
    }
    {
        int tx, ty;
        cin >> tx >> ty;
        assert(2 * tx == a[0].first && 2 * ty == a[0].second);
    }

    int result = 0;
    for (int i = 0; i < n; ++i) {
        int j = i + 1;
        if (j == n) {
            j = 0;
        }

        pair<int, int> p = GetSum(a[j], GetD(a[i], a[j]));

        if (IsInside(p, GetD(a[i], a[j]), a)) {
            ++result;
        }
    }
    cout << result << endl;

    return 0;
}