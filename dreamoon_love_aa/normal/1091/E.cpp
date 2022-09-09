#include <algorithm>
#include <iostream>
using namespace std;

using ll = long long;

int a[500001], b[500001], n;

int check(int x) {
    if(x == -1) {
        return -1;
    }
    copy(a + 1, a + n + 1, b + 1);
    b[0] = x;
    for(int i = 0; i < n && b[i] < b[i + 1]; i++) {
        swap(b[i], b[i + 1]);
    }
    ll left = 0, right = 0;
    for(ll i = 0, j = n, k = 1; i <= n; i++, k++) {
        while(j > i && b[j] < k) {
            right += b[j];
            j--;
        }
        while(j < i || (j < n && b[j + 1] >= k)) {
            right -= b[j + 1];
            j++;
        }
        left += b[i];
        if(left > k * (k - 1) + right + k * (j - i)) {
            return b[i] <= x ? 1 : -1;
        }
    }
    return 0;
}

void solve() {
    cin >> n;
    bool flag = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        flag ^= a[i] & 1;
    }
    sort(a + 1, a + n + 1, greater<int>());
    int l = 0, r = n - flag >> 1, mid;
    while(l < r) {
        mid = l + r >> 1;
        if(check(mid * 2 + flag) == -1) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    int start = r;
    l = 0, r = n - flag >> 1;
    while(l < r) {
        mid = l + r + 1 >> 1;
        if(check(mid * 2 + flag) == 1) {
            r = mid - 1;
        } else {
            l = mid;
        }
    }
    if(check(start * 2 + flag) || check(r * 2 + flag) || start > r) {
        cout << -1;
        return;
    }
    for(int i = start; i <= r; i++) {
        cout << i * 2 + flag << ' ';
    }
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    solve();
    return 0;
}