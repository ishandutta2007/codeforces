#include <bits/stdc++.h>
using namespace std;

long long GetAnswer(const vector<int>& a, const vector<int>& b, int n, int m)
{
    vector<int> c(n, 0);
    int last_pos = 0;
    int dx = +1;
    ++c[last_pos];
    long long dist = 0;
    for (int step = 1; step < m; ++step) {
        if (last_pos + dx == n || last_pos + dx < 0) {
            dx *= -1;
        }
        last_pos += dx;
        ++c[last_pos];
        dist += a[min(last_pos - dx, last_pos)];
    }
    int u = 0;
    for (int i = 0; i < n; ++i) {
        if (c[i] == b[i]) {
            ++u;
        }
    }
    long long ans = -2;
    if (u == n) {
        ans = dist;
    }
    for (int start_pos = 1; start_pos < n; ++start_pos) {
        dist -= a[start_pos - 1];
        if (c[start_pos - 1] == b[start_pos - 1]) {
            --u;
        }
        --c[start_pos - 1];
        if (c[start_pos - 1] == b[start_pos - 1]) {
            ++u;
        }
        if (last_pos + dx == n || last_pos + dx < 0) {
            dx *= -1;
        }
        last_pos += dx;
        if (c[last_pos] == b[last_pos]) {
            --u;
        }
        ++c[last_pos];
        if (c[last_pos] == b[last_pos]) {
            ++u;
        }
        dist += a[min(last_pos - dx, last_pos)];
        if (u == n) {
            if (ans == -2) {
                ans = dist;
            } else if (ans != dist) {
                ans = -1;
            } 
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> temp(n);
    for (int i = 0; i < n; ++i) {
        cin >> temp[i];
    }
    vector<int> a(n - 1);
    for (int i = 0; i + 1 < n; ++i) {
        a[i] = temp[i + 1] - temp[i];
    }
    int m;
    cin >> m;
    vector<int> b(n, 0);
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        ++b[x - 1];
    }
    long long ans1 = GetAnswer(a, b, n, m);
    reverse(temp.begin(), temp.end());
    reverse(b.begin(), b.end());
    for (int i = 0; i + 1 < n; ++i) {
        a[i] = abs(temp[i + 1] - temp[i]);
    }
    long long ans2 = GetAnswer(a, b, n, m);
    long long ans;
    
    if (ans1 == -2) {
        ans = ans2;
    } else if (ans2 == -2) {
        ans = ans1;
    } else if (ans1 == -1 || ans2 == -1) {
        ans = -1;
    } else if (ans1 != ans2) {
        ans = -1;
    } else {
        ans = ans1;
    }
    
    cout << ans << endl;
    
    
    return 0;
}