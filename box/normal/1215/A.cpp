#include <iostream>
#include <algorithm>
using namespace std;

int miin(int t1, int t2, int t1l, int t2l, int n) {
    n -= t1*(t1l-1);
    n -= t2*(t2l-1);
    return max(n, 0);
}

int maax(int t1, int t2, int t1l, int t2l, int n) {
    if(t2l < t1l) {
        swap(t1, t2);
        swap(t1l, t2l);
    }
    if(t1l * t1 >= n) return n/t1l;
    n -= t1l*t1;
    return t1+n/t2l;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t1, t2, t1l, t2l, n; cin >> t1 >> t2 >> t1l >> t2l >> n;
    // every member in t1 receives t1l-1, and every member in t2 receives t2l-1
    cout << miin(t1, t2, t1l, t2l, n) << ' ' << maax(t1, t2, t1l, t2l, n) << endl;
}