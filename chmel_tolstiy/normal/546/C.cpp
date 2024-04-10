#include <iostream>
#include <deque>

using namespace std;

int main() {
    int n; cin >> n;
    cin >> n;
    deque<int> a(n); for (int i = 0; i < n; ++i) cin >> a[i];
    cin >> n;
    deque<int> b(n); for (int i = 0; i < n; ++i) cin >> b[i];
    
    const int INF = 4e7;
    int cnt = 0;
    while (a.size() && b.size()) {
        int x = a.front(); a.pop_front();
        int y = b.front(); b.pop_front();
        if (x > y) {
            a.push_back(y); a.push_back(x);
        } else {
            b.push_back(x); b.push_back(y);
        }
        ++cnt;
        if (cnt > INF)
            break;
    }
    
    if (cnt > INF)
        cout << -1 << endl;
    else
        cout << cnt << ' ' << (a.size() == 0 ? 2 : 1) << endl;
    return 0;
}