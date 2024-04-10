#include <bits/stdc++.h>
using namespace std;

template<typename T>
void sci(T& t) {
    cin >> t;
}

template<typename T, typename... Ts>
void sci(T& t, Ts&... ts) {
    sci(t);
    sci(ts...);
}

#define scid(vars...) int vars; sci(vars)
#define scidl(vars...) lint vars; sci(vars)
#define scidd(vars...) double vars; sci(vars)
#define scids(vars...) string vars; sci(vars)

template <typename T, typename Cmp=std::greater<int>>
using heap = priority_queue<T, std::vector<T>, Cmp>;

typedef long long lint;

int a[111];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    scid(n);
    priority_queue<pair<int, int> > q;
    vector<pair<int, int> > ans;
    for (int i = 0; i < n; i++) {
        sci(a[i]);
        if (i) {
            q.push({a[i], i});
        }
    }
    queue<int> b;
    b.push(0);
    while (!b.empty()) {
        int x = b.front();
        b.pop();
        while (!q.empty() && a[x] > 0) {
            auto y = q.top();
            q.pop();
            b.push(y.second);
            ans.push_back({x, y.second});
            a[x]--;
        }
    }
    
    if (!q.empty()) {
        cout << -1;
        return 0;
    }
    
    cout << ans.size() << "\n";
    for (auto i : ans) {
        cout << i.first + 1 << " " << i.second + 1 << "\n"; 
    }
    

    return 0;
}