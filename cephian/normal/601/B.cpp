#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int a[100005];
int d[100005];
int lb[100005];
int rb[100005];

int main() {
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < n-1; ++i)
        d[i] = abs(a[i+1] - a[i]);
    vector<pii> bg;
    for(int i = 0; i < n-1; ++i) {
        while(!bg.empty() && bg.back().first < d[i])
            bg.pop_back();
        if(!bg.empty())
            lb[i] = bg.back().second;
        else
            lb[i] = -1;
        bg.push_back(pii(d[i], i));
    }
    bg.clear();
    for(int i = n-1; i >= 0; --i) {
        while(!bg.empty() && bg.back().first <= d[i])
            bg.pop_back();
        if(!bg.empty())
            rb[i] = bg.back().second;
        else
            rb[i] = n;
        bg.push_back(pii(d[i], i));
    }

    for(int i = 0; i < q; ++i) {
        ll ans = 0;
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        for(int i = a; i < b; ++i)
            ans += ll(d[i]) * (i - max(a-1, lb[i])) * (min(b, rb[i]) - i);
        cout << ans << "\n";
    }
    return 0;
}