#include<bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define MP make_pair
#define PB emplace_back
using namespace std;
void solve() {
    int n;
    scanf("%d", &n);
    map<int, int> cnt;
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        cnt[x]++;
    }
    vector<int> d;
    for(auto [a, b]: cnt){
        d.push_back(b);
    }
    sort(d.begin(), d.end(), greater<int>());
    int ma = 0;
    for(int i = 0; i < SZ(d); i++) {
        ma = max(ma, (i + 1) * d[i]);
    }
    printf("%d\n", n - ma);
}
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        solve();
    }
    return 0;
}