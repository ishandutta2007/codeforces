#include <algorithm>
#include <array>
#include <bitset>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#include <cassert>
using namespace std;

struct TQuery {
    pair<int, int> SCoords;
    pair<int, int> TCoords;
};

string s;
string t;

vector<int> sBCount;
vector<int> tBCount;

vector<int> sLastB;
vector<int> tLastB;

int q;
vector<TQuery> qs;

int GetCount(int l, int r, const vector<int>& count) {
    return l == 0 ? count[r] : count[r] - count[l - 1];
}

int GetLast(int l, int r, const vector<int>& last) {
    return last[r] < l ? -1 : last[r];
}

int GetSBCount(int l, int r) {
    return GetCount(l, r, sBCount);
}

int GetSLastB(int l, int r) {
    return GetLast(l, r, sLastB);
}

int GetTBCount(int l, int r) {
    return GetCount(l, r, tBCount);
}

int GetTLastB(int l, int r) {
    return GetLast(l, r, tLastB);
}

void Build(const string& s, vector<int>& count, vector<int>& last) {
    const int n = s.size();
    count.resize(n);
    last.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        count[i] = (s[i] == 'B' || s[i] == 'C');
        if (i > 0) {
            count[i] += count[i - 1];
        }
        last[i] = -1;
        if (i > 0) {
            last[i] = last[i - 1];
        }
        if (s[i] == 'B' || s[i] == 'C') {
            last[i] = i;
        }
    }
}

bool Check(const pair<int, int>& sc, const pair<int, int>& tc) {
    const int sBCount = GetSBCount(sc.first, sc.second);
    const int tBCount = GetTBCount(tc.first, tc.second);
    if (sBCount > tBCount) {
        return false;
    }
    if ((tBCount - sBCount) % 2 != 0) {
        return false;
    }
    const int tLastB = GetTLastB(tc.first, tc.second);
    const int sLastB = GetSLastB(sc.first, sc.second);
    const int sAEndCount = (sLastB == -1 ? sc.second - sc.first + 1 : sc.second - sLastB);
    const int tAEndCount = (tLastB == -1 ? tc.second - tc.first + 1 : tc.second - tLastB);
    if (sAEndCount < tAEndCount) {
        return false;
    }
    if (sBCount == tBCount) {
        return (sAEndCount - tAEndCount) % 3 == 0;
    }
    if (sBCount == 0) {
        return sAEndCount > tAEndCount;
    }
    return true;
}

void Solve() {
    Build(s, sBCount, sLastB);
    Build(t, tBCount, tLastB);
    for (int i = 0; i < q; ++i) {
        cout << Check(qs[i].SCoords, qs[i].TCoords);
    }
    cout << endl;
}

bool Read() {
    if (!(cin >> s >> t)) {
        return false;
    }
    cin >> q;
    qs.resize(q);
    for (int i = 0; i < q; ++i) {
        cin >> qs[i].SCoords.first >> qs[i].SCoords.second
            >> qs[i].TCoords.first >> qs[i].TCoords.second;
        --qs[i].SCoords.first;
        --qs[i].SCoords.second;
        --qs[i].TCoords.first;
        --qs[i].TCoords.second;
    }
    return true;
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (Read()) {
        Solve();
    }

    return 0;
}