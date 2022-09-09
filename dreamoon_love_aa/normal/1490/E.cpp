#include<bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define MP make_pair
#define PB emplace_back
using namespace std;
void solve() {
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> person;
    for(int i = 1; i <= n; i++) {
        int token_num;
        scanf("%d", &token_num);
        person.PB(MP(token_num, i));
    }
    sort(person.begin(), person.end());
    int l = 0, r = n - 1;
    while(l < r) {
        int m = (l + r) / 2;
        long long now = 0;
        for(int i = 0; i <= m; i++) {
            now += person[i].first;
        }
        bool fail = 0;
        for(int i = m + 1; i < n; i++) {
            if(now < person[i].first) {
                fail = 1;
                break;
            }
            now += person[i].first;
        }
        if(!fail) r = m;
        else l = m + 1;
    }
    vector<int> ans;
    for(int i = l; i < n; i++) {
        ans.PB(person[i].second);
    }
    sort(ans.begin(), ans.end());
    printf("%d\n", SZ(ans));
    for(int i = 0; i < SZ(ans); i++) {
        if(i) { printf(" "); }
        printf("%d", ans[i]);
    }
    puts("");
}
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        solve();
    }
    return 0;
}