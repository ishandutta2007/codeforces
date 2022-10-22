#include <bits/stdc++.h>

using namespace std;
const int N = 10234;
int a[N], cnt[2];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i], cnt[a[i] % 2]++;
    int x;
    if (cnt[0] == 1)
        x = 0;
    else
        x = 1;
    for (int i = 0; i < n; i++)
        if (x == a[i] % 2)
            cout << i + 1 << '\n';
}