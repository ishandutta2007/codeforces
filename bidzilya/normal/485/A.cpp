#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int a, m;
    cin >> a >> m;

    vector<int> used(m + 1, 0);
    a %= m;

    used[a] = 1;
    while (true) {
        a = (a + a % m) % m;
        if (used[a]) {
            break;
        }
        used[a] = 1;
    }

    if (used[0]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}