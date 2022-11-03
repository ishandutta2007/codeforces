#include <algorithm>
#include <array>
#include <bitset>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>

#include <cassert>
using namespace std;

struct TBox {
    int A;
    int B;
    int C;
};

TBox g;
int n;
vector<TBox> a;

struct TLine {
    deque<std::pair<int, int>> Points;

    long long BadCount = 0;

    void DoPopFront() {
        if (Points.size() > 1) {
            BadCount -= GetBadCount(1);
        }
        BadCount -= GetBadCount(0);
        Points.pop_front();
        if (!Points.empty()) {
            BadCount += GetBadCount(0);
        }
    }

    void DoPopBack() {
        BadCount -= GetBadCount(Points.size() - 1);
        Points.pop_back();
    }

    void DoPushFront(const pair<int, int>& point) {
        if (!Points.empty()) {
            BadCount -= GetBadCount(0);
        }
        Points.push_front(point);
        BadCount += GetBadCount(0);
        if (Points.size() > 1) {
            BadCount += GetBadCount(1);
        }
    }

    void DoPushBack(const pair<int, int>& point) {
        Points.push_back(point);
        BadCount += GetBadCount(Points.size() - 1);
    }

    void PushFront(const pair<int, int>& point) {
        while (!Points.empty() && Points.front().second <= point.second) {
            DoPopFront();
        }
        DoPushFront(point);
    }

    void PushBack(const pair<int, int>& point) {
        while (!Points.empty() && Points.back().first <= point.first) {
            DoPopBack();
        }
        DoPushBack(point);
    }

    long long GetBadCount(const int idx) const {
        if (idx == 0) {
            return 1LL * Points[idx].second * Points[idx].first;
        } else {
            return 1LL * (Points[idx].second - Points[idx - 1].second) * Points[idx].first;
        }
    }
};

long long GetGoodCount(const TLine& line) {
    return 1LL * g.B * g.C - line.BadCount;
}

TLine Build() {
    std::sort(a.begin(), a.end(), [] (const TBox& lhs, const TBox& rhs) {
        return lhs.C < rhs.C;
    });
    TLine result;
    for (int i = 0; i < n; ++i) {
        result.PushBack(make_pair(a[i].B, a[i].C));
    }
    return result;
}

void Solve() {
    auto line = Build();

    sort(a.begin(), a.end(), [] (const TBox& lhs, const TBox& rhs) {
        return lhs.A < rhs.A;
    });

    long long result = 0;
    result += 1LL * (g.A - a.back().A) * GetGoodCount(line);
    for (int i = (int) a.size() - 1; i >= 0; --i) {
        line.PushFront(make_pair(g.B, a[i].C));
        line.PushBack(make_pair(a[i].B, g.C));
        const int prev = (i == 0 ? 0 : a[i - 1].A);
        result += 1LL * (a[i].A - prev) * GetGoodCount(line);
    }

    cout << result << endl;
}

bool Read() {
    if (!(cin >> n >> g.A >> g.B >> g.C)) {
        return false;
    }
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].A >> a[i].B >> a[i].C;
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