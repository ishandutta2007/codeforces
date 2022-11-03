#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <set>

#include <cassert>
using namespace std;

struct TPoint {
    long long X;
    long long Y;
    int Id;
};

int n;
long long k;
vector<TPoint> points;

struct TEvent {
    long long Val;
    int Id;
    bool Start;
};

bool operator < (const TEvent& lhs, const TEvent& rhs) {
    if (lhs.Val < rhs.Val) {
        return true;
    }
    if (lhs.Val == rhs.Val) {
        if (!lhs.Start && rhs.Start) {
            return true;
        }
        if (lhs.Start == rhs.Start) {
            return lhs.Id < rhs.Id;
        }
    }
    return false;
}

using TIterator = set<TEvent>::iterator;

vector<long long> result;

template<typename TOnAdd, typename TOnDel, typename TOnDo>
void Traverse(const set<TEvent>& events, TOnAdd add, TOnDel del, TOnDo dof) {
    if (events.empty()) {
        return;
    }

    long long maxVal = (*events.rbegin()).Val;

    TIterator beg = events.begin();

    while ((*beg).Val != maxVal) {
        int val = (*beg).Val;

        while (!(*beg).Start && (*beg).Val == val) {
            del((*beg).Id);
            ++beg;
        }

        while ((*beg).Start && (*beg).Val == val) {
            add((*beg).Id);
            ++beg;
        }

        long long nVal = (*beg).Val;

        dof(val, nVal);
    }

    while (beg != events.end()) {
        del((*beg).Id);
        ++beg;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    points.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].X >> points[i].Y;
        points[i].Id = i;
    }

    result.assign(n + 1, 0);

    set<TEvent> evs;
    for (int i = 0; i < n; ++i) {
        const TPoint& p = points[i];
        evs.insert(TEvent{p.X - k + 1, p.Id, true});
        evs.insert(TEvent{p.X + 1, p.Id, false});
    }

    set<TEvent> curEvs;

    auto add1 = [&curEvs] (int id) {
        const TPoint& p = points[id];
        curEvs.insert(TEvent{p.Y - k + 1, p.Id, true});
        curEvs.insert(TEvent{p.Y + 1, p.Id, false});
    };

    auto del1 = [&curEvs] (int id) {
        const TPoint& p = points[id];
        curEvs.erase(TEvent{p.Y - k + 1, p.Id, true});
        curEvs.erase(TEvent{p.Y + 1, p.Id, false});
    };

    vector<int> used(n, 0);
    int usedCount = 0;
    auto dof1 = [&curEvs, &used, &usedCount] (long long v1, long long v2) {
        long long mul = v2 - v1;
        auto add2 = [&used, &usedCount] (int id) {
            ++used[id];
            if (used[id] == 1) {
                ++usedCount;
            }
        };
        auto del2 = [&used, &usedCount] (int id) {
            --used[id];
            if (used[id] == 0) {
                --usedCount;
            }
        };
        auto dof2 = [&usedCount, &mul] (long long v1, long long v2) {
            long long mul2 = v2 - v1;
            result[usedCount] += mul * mul2;
        };
        Traverse(curEvs, add2, del2, dof2);
    };

    Traverse(evs, add1, del1, dof1);

    for (int i = 1; i <= n; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}