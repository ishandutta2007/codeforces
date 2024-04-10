#include <iostream>

using namespace std;

char s[1<<10];
int n;
int a[1<< 10];

void solve() {
    cin >> n;
    cin >> s;
    a[0] = 1;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == '=') a[i+1] = a[i];
        if (s[i] == 'R') a[i+1] = a[i] + 1;
        if (s[i] == 'L') {
            a[i+1] = 1;
            for (int j = i; j >= 0; j--) {
                if (s[j] == '=') a[j] = a[j+1];
                if (s[j] == 'L' && a[j] <= a[j+1]) a[j] = a[j+1] + 1;
                if (s[j] == 'R' && a[j] >= a[j+1]) a[j] = a[j+1] - 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (i) cout << ' ';
        cout << a[i];
    }
    cout << endl;
}

int main() {
    solve();
    return 0;
}