#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>

#include <cassert>
using namespace std;

struct TRect {
    int X1;
    int Y1;
    int X2;
    int Y2;
};

bool IsInside(const TRect& out, const TRect& inner) {
    return out.X1 <= inner.X1 && out.X2 >= inner.X2 &&
        out.Y1 <= inner.Y1 && out.Y2 >= inner.Y2;
}

/*
const TRect firstResult{2, 2, 2, 2};
const TRect secondResult{3, 4, 3, 5};
*/

int GetResult(int x1, int y1, int x2, int y2) {
    cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    int result;
    /*
    result = 0;
    result += IsInside(TRect{x1, y1, x2, y2}, firstResult);
    result += IsInside(TRect{x1, y1, x2, y2}, secondResult);
    */
    cin >> result;
    return result;
}

int n;

template <typename TConstructRectFunc, typename TCheckFunc>
int GetBinary(TConstructRectFunc constructFunc, TCheckFunc checkFunc, int ba, bool inc) {
    int bl = 1;
    int br = n;
    while (bl <= br) {
        int bm = (bl + br) >> 1;

        int x1, y1, x2, y2;

        constructFunc(x1, y1, x2, y2, bm);

        if (checkFunc(GetResult(x1, y1, x2, y2))) {
            ba = bm;
            if (inc) {
                bl = bm + 1;
            } else {
                br = bm - 1;
            }
        } else {
            if (inc) {
                br = bm - 1;
            } else {
                bl = bm + 1;
            }
        }
    }
    return ba;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    vector<int> lefts;
    vector<int> rights;

    vector<int> ups;
    vector<int> downs;

    for (int x = 0; x < 2; ++x) {
        rights.push_back(GetBinary(
            [] (int& x1, int& y1, int& x2, int& y2, int bm) {
                y1 = 1;
                y2 = n;
                x1 = 1;
                x2 = bm;
            },
            [x] (int value) {
                return value <= x;
            },
            0,
            true
        ) + 1);
    }

    for (int x = 0; x < 2; ++x) {
        lefts.push_back(GetBinary(
            [] (int& x1, int& y1, int& x2, int& y2, int bm) {
                y1 = 1;
                y2 = n;
                x1 = bm;
                x2 = n;
            },
            [x] (int value) {
                return value <= x;
            },
            n + 1,
            false
        ) - 1);
    }

    for (int x = 0; x < 2; ++x) {
        ups.push_back(GetBinary(
            [] (int& x1, int& y1, int& x2, int& y2, int bm) {
                y1 = 1;
                y2 = bm;
                x1 = 1;
                x2 = n;
            },
            [x] (int value) {
                return value <= x;
            },
            0,
            true
        ) + 1);
    }

    for (int x = 0; x < 2; ++x) {
        downs.push_back(GetBinary(
            [] (int& x1, int& y1, int& x2, int& y2, int bm) {
                y1 = bm;
                y2 = n;
                x1 = 1;
                x2 = n;
            },
            [x] (int value) {
                return value <= x;
            },
            n + 1,
            false
        ) - 1);
    }

    for (int li = 0; li < 2; ++li) {
        for (int ri = 0; ri < 2; ++ri) {
            for (int di = 0; di < 2; ++di) {
                for (int ui = 0; ui < 2; ++ui) {
                    bool ok = true;

                    int x11, x12, y11, y12;
                    {
                        x11 = lefts[li];
                        x12 = rights[ri];
                        y11 = downs[di];
                        y12 = ups[ui];

                        ok &= (x11 <= x12 && y11 <= y12 && GetResult(x11, y11, x12, y12) == 1);
                    }

                    int x21, x22, y21, y22;
                    {
                        x21 = lefts[1 - li];
                        x22 = rights[1 - ri];
                        y21 = downs[1 - di];
                        y22 = ups[1 - ui];

                        ok &= (x21 <= x22 && y21 <= y22 && GetResult(x21, y21, x22, y22) == 1);
                    }

                    if (ok) {
                        cout << "! " << x11 << " " << y11 << " " << x12 << " " << y12 << " ";
                        cout << x21 << " " << y21 << " " << x22 << " " << y22 << endl;
                        return 0;
                    }
                }
            }
        }
    }

    assert(false);

    return 0;
}