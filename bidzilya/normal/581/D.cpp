#include <iostream>
#include <deque>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <map>
#include <cassert>
using namespace std;

inline int GetBit(int mask, int num)
{
    return (mask >> num) & 1;
}

const char kEmpty = '.';

int n;
vector<vector<char> > field;

bool IsFilled()
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (field[i][j] == kEmpty) {
                return false;
            }
        }
    }
    return true;
}

void Clear()
{
    field.assign(n, vector<char>(n, kEmpty));
}

void Show()
{
    cout << n << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << field[i][j];
        }
        cout << endl;
    }
}

bool CanFill(int ci, int cj, int si, int sj, char c)
{
    if (ci + si - 1 >= n || cj + sj - 1 >= n) {
        return false;
    }
    for (int i = ci; i < ci + si; ++i) {
        for (int j = cj; j < cj + sj; ++j) {
            if (field[i][j] != kEmpty) {
                return false;
            }
            field[i][j] = c;
        }
    }
    return true;
}

bool CanFill(int si, int sj, char c)
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (field[i][j] == kEmpty) {
                return CanFill(i, j, si, sj, c);
            }
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    int square = x1 * y1 + x2 * y2 + x3 * y3;

    n = sqrt(square);
    while (n * n < square) {
        ++n;
    }
    while (n * n > square) {
        --n;
    }

    if (n * n != square) {
        cout << -1 << endl;
        return 0;
    }

    vector<pair<pair<int, int>, char> > a(3);
    a[0] = make_pair(make_pair(x1, y1), 'A');
    a[1] = make_pair(make_pair(x2, y2), 'B');
    a[2] = make_pair(make_pair(x3, y3), 'C');

    do {
        for (int mask = 0; mask < (1 << 3); ++mask) {
            for (int num = 0; num < 3; ++num) {
                if (GetBit(mask, num)) {
                    swap(a[num].first.first, a[num].first.second);
                }
            }
            bool good = true;
            Clear();
            for (int i = 0; i < 3; ++i) {
                if (!CanFill(a[i].first.first, a[i].first.second, a[i].second)) {
                    good = false;
                    break;
                }
            }
            if (good && IsFilled()) {
                Show();
                return 0;
            }
            for (int num = 0; num < 3; ++num) {
                if (GetBit(mask, num)) {
                    swap(a[num].first.first, a[num].first.second);
                }
            }
        }
    } while (next_permutation(a.begin(), a.end()));

    cout << -1 << endl;

    return 0;
}