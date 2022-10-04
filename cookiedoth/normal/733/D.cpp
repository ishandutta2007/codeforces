#include <iostream>
#include <algorithm>

using namespace std;

struct box {
    int d1, d2, d3, num;
};
const int mx = 200000;
int n, i1, i2, Max = 0, ii, maX = 0;
box a[mx], b[mx];

void srt(int & a, int & b, int & c)
{
    if (a < b) {swap(a, b);}
    if (a < c) {swap(a, c);}
    if (b < c) {swap(b, c);}
}

bool comp(box b1, box b2) {
    if (b1.d1 != b2.d1) return (b1.d1 > b2.d1);
    if (b1.d2 != b2.d2) return (b1.d2 > b2.d2);
    return (b1.d3 > b2.d3);
}

void update(int i) {
    if ((i < n-1) && (a[i].d1 == a[i+1].d1) && (a[i].d2 == a[i+1].d2) && (min(a[i].d1, min(a[i].d2, a[i].d3 + a[i+1].d3)) > Max)) {
        Max = min(a[i].d1, min(a[i].d2, a[i].d3 + a[i+1].d3));
        i1 = a[i].num;
        i2 = a[i+1].num;
    }
}

void solve() {
    sort(a, a+n, comp);
    update(0);
    for (int i = 1; i<n; ++i) {
        if ((a[i].d1 != a[i-1].d1) || (a[i].d2 != a[i-1].d2)) update(i);
    }
}

int main()
{
    int temp;
    cin >> n;
    for (int i = 0; i<n; ++i) {
        cin >> b[i].d1 >> b[i].d2 >> b[i].d3;
        b[i].num = i;
    }
    for (int i = 0; i<n; ++i) {
        a[i].num = i;
        a[i].d1 = b[i].d1; a[i].d2 = b[i].d2; a[i].d3 = b[i].d3;
        srt(a[i].d1, a[i].d2, a[i].d3);
    }
    solve();
    for (int i = 0; i<n; ++i) {
        temp = min (b[i].d1, min(b[i].d2, b[i].d3));
        if (temp > maX) {
            maX = temp;
            ii = i;
        }
    }
    if (Max >= maX) {
        cout << 2 << endl;
        cout << i1 + 1 << " " << i2 + 1;
    }
    else {
        cout << 1 << endl;
        cout << ii + 1;
    }
    return 0;
}