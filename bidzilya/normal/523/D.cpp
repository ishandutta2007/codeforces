#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    vector<long long> s(n), m(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i] >> m[i];
    }

    priority_queue<long long, vector<long long>, greater<long long> > q;

    for (int i = 0; i < k; ++i) {
        q.push(0);
    }

    for (int i = 0; i < n; ++i) {
        long long rs = max(s[i], q.top());
        q.pop();
        cout << rs + m[i] << '\n';
        q.push(rs + m[i]);
    }

    cout.flush();

    return 0;
}