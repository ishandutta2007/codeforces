#include <bits/stdc++.h>
using namespace std;
using namespace std::placeholders;

#define llong long long 
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define all(x) x.begin(), x.end()
// #define rand __rand
// mt19937 rng(chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64
// template<class T = int> T rand(T range = numeric_limits<T>::max()) {
    // return (T)(rng() % range);
// }

#define maxn 301010
int n;
int a[maxn];
int next_greater[maxn];
int ans[maxn] = {0};
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    rep(i, n) {
        cin >> a[i];
        a[i + n] = a[i];
        a[i + 2 * n] = a[i];
    }

    deque<int> st;
    rep(i, 3 * n) {
        for (; len(st) and a[st.back()] <= a[i]; st.pop_back()) {
            next_greater[st.back()] = i;
        }
        for (; len(st) and a[st.front()] > a[i] * 2; st.pop_front()) {
            next_greater[st.front()] = -1;
            ans[st.front()] = i - st.front();
        }
        st.push_back(i);
    }
    for (; len(st); st.pop_back()) {
        ans[st.back()] = -1;
        next_greater[st.back()] = 2 * n;
    }

    for (int i = 3 * n; i--; ) {
        if (next_greater[i] == -1) continue;
        if (ans[i] != 0) continue;
        if (ans[next_greater[i]] == -1) ans[i] = -1;
        else ans[i] = ans[next_greater[i]] + next_greater[i] - i;
    }
    rep(i, n) cout << ans[i] << ' ';

    return 0;
}