#include<bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define MP make_pair
#define PB emplace_back
using namespace std;
const int SIZE = 1e6;
int a[SIZE];
int b[SIZE];
void solve() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    vector<pair<int, int>>pp;
    for(int i = 0; i < n; i++) {
        pp.push_back(make_pair(a[i], b[i]));
    }
    sort(pp.begin(), pp.end());
    long long sum = 0;
    long long an = 1e18;
    for(int i = n; i >= 0; i--) {
        an = min(an, max(sum, i > 0 ? pp[i - 1].first : 0LL));
        if(i > 0) {
            sum += pp[i - 1].second;
        }
    }
    printf("%lld\n", an);
}
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        solve();
    }
    return 0;
}