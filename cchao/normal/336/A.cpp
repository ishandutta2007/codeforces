#include <cstdio>
#include <iostream>
using namespace std;
int f(int x) {
    return x > 0 ? 1 : -1;
}

int main() {
    int x, y, s;
    cin >> x >> y;
    int t;
    if(f(x) == f(y)) t = x + y, s = -1;
    else t = y - x, s = 1;

    pair<int, int> a = make_pair(0, t);
    pair<int, int> b = make_pair(-t*s, 0);
    if(a > b) swap(a, b);
    cout << a.first << ' ' << a.second << ' ';
    cout << b.first << ' ' << b.second << endl;
    return 0;
}