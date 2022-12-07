// https://codeforces.com/problemset/problem/1294/B

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
#define MAXN 1000

int n;

struct Point {
    int x;
    int y;
};

Point p[MAXN];

bool comp(Point a, Point b) {
    if(a.x==b.x) return a.y<b.y;
    return a.x<b.x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    int t;
    cin >> t;
while(t--) {
    cin >> n;
    forn(i, n) cin >> p[i].x >> p[i].y;
    sort(p,p+n,comp);
    int max = 0, temp = 1;
    forn(i, n) {
        if(p[i].y>=max) max=p[i].y;
        else {
            cout << "NO" << endl;
            temp = 0;
            break;
        }
    }
    if(temp==0) continue;
    cout << "YES" << endl;
    int tx = 0, ty = 0;
    forn(i, n) {
        for(tx; tx<p[i].x; tx++) cout << "R";
        for(ty; ty<p[i].y; ty++) cout << "U";
    }
    cout << endl;
}
    return 0;
}