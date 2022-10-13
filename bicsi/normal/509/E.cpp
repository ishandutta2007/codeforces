#include <bits/stdc++.h>

using namespace std;

int main() {
    string s; cin >> s;
    int n = s.size();
    vector<double> x(n + 1, 0), y(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || 
            s[i] == 'O' || s[i] == 'U' || s[i] == 'Y') {
            
            int left_max = i + 1;
            int right_max = n - i;
            x[1] += 1;
            x[min(left_max, right_max)] -= 1;
            y[min(left_max, right_max)] += min(left_max, right_max);
            x[max(left_max, right_max)] -= 1;
            y[max(left_max, right_max)] += max(left_max, right_max);
        }
    }

    double ans = 0;
    for (int i = 1; i <= n; ++i) {
        x[i] += x[i - 1];
        y[i] += y[i - 1];
        ans += (1.0 * x[i] * i + y[i]) / i;
    }
    cout << fixed << setprecision(20) << ans << endl;

    return 0;
}