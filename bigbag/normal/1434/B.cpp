#include <bits/stdc++.h>

using namespace std;

const int max_n = 200111, inf = 1000111222;

void wa() {
    puts("NO");
    exit(0);
}

int n, a[max_n];
char tp[max_n];
vector<pair<int, int>> v;
set<int> q;

bool check() {
    multiset<int> q;
    for (int i = 0; i < n; ++i) {
        if (tp[i] == '+') {
            q.insert(a[i]);
        } else {
            if (q.empty()) {
                return false;
            }
            auto it = q.begin();
            if (*it != a[i]) {
                return false;
            }
            q.erase(it);
        }
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    n *= 2;
    for (int i = 0; i < n; ++i) {
        scanf("\n%c", &tp[i]);
        if (tp[i] == '-') {
            scanf("%d", &a[i]);
            v.push_back({a[i], i});
        } else {
            q.insert(i);
        }
        //cout << tp[i] << " " << a[i] << endl;
    }
    sort(v.begin(), v.end());
    for (auto p : v) {
        auto it = q.lower_bound(p.second);
        if (it == q.begin()) {
            wa();
        }
        --it;
        a[*it] = p.first;
        q.erase(it);
    }
    if (!check()) {
        wa();
    }
    puts("YES");
    for (int i = 0; i < n; ++i) {
        if (tp[i] == '+') {
            printf("%d ", a[i]);
        }
    }
    puts("");
    return 0;
}