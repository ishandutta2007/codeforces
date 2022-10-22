#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool is_dif (int x) {
    vector <int> a;
    while (x) {
        a.push_back(x % 10);
        x /= 10;
    }
    sort (a.begin(), a.end());
    bool f = true;
    for (int i = 0; i < a.size() - 1; i++) {
        if (a[i] == a[i + 1]) {
            f = false;
            break;
       }
    }
    return f;
}
int main(){
    int l, r;
    cin >> l >> r;
    for (int i = l; i <= r; i++) {
        if (is_dif (i)) {
            cout << i;
            return 0;
        }
    }
    cout << -1;
}