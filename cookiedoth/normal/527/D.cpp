/************
*           *
*   HELLO   *
*           *
************/

#include <iostream>
#include <algorithm>

using namespace std;

const int mx = 300000;

struct vert {
    int x, w;
};

bool comp (const vert& f1, const vert& f2) {
    return f1.x + f1.w < f2.x + f2.w;
}

int i, ans, l, n;
vert m[mx];

int main()
{
    cin >> n;
    for (i = 0; i<n; i++) {
        cin >> m[i].x >> m[i].w;
    }
    sort(m, m+n, comp);
    ans = 1;
    l = 0;
    for (i = 1; i<n; i++) {
        if (m[i].x-m[i].w>=m[l].x+m[l].w) {
            l = i;
            ans++;
        }
    }
    cout << ans;
    return 0;
}