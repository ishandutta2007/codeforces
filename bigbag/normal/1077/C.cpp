#include <bits/stdc++.h>

using namespace std;

const int max_n = 202222, inf = 1000111222;

int n, a[max_n];
long long sum;
multiset<int> q;
vector<int> ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        sum += a[i];
        q.insert(a[i]);
    }
    for (int i = 0; i < n; ++i) {
        q.erase(q.find(a[i]));
        sum -= a[i];
        if (sum - *q.rbegin() == *q.rbegin()) {
            ans.push_back(i + 1);
        }
        sum += a[i];
        q.insert(a[i]);
    }
    printf("%d\n", ans.size());
    for (int id : ans) {
        printf("%d ", id);
    }
    puts("");
    return 0;
}