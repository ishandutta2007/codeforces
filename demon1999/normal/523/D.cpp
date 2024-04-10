#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    priority_queue<long long, vector<long long>, greater<long long> > q;
    for (int i = 0; i < k; ++i) q.push(0);
    long long x, y;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        long long v = q.top();
        q.pop();
        if (v < x) v = x;
        printf("%I64d\n", v + y);
        q.push(v + y);
    }

    return 0;
}