#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(1 << (n + 1));
    for (int i = 2; i < (1 << (n + 1)); ++i) {
        cin >> a[i];
    }
    int answer = 0;
    for (int lvl = n; lvl >= 1; --lvl) {
        int lf = (1 << lvl);
        int rg = (1 << (lvl + 1)) - 1;
        for (int i = lf; i <= rg; i += 2) {
            answer += abs(a[i] - a[i + 1]);
            a[i / 2] += max(a[i], a[i + 1]);
        }
    }
    cout << answer << endl;

    return 0;
}