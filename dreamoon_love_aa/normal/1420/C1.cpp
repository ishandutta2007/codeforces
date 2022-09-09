#include<bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define MP make_pair
#define PB emplace_back
using namespace std;
const int SIZE = 3.1e5;
int a[SIZE];
bool big(int pos) {
    return a[pos] > max(a[pos - 1], a[pos + 1]);
}
bool small(int pos) {
    return a[pos] < min(a[pos - 1], a[pos + 1]);
}
set<int>big_pos, small_pos;
long long now;
void clear(int i) {
    if(big(i)) {
        if(big_pos.count(i)){
            big_pos.erase(i);
            now -= a[i];
        }
    } else if(small(i)){
        if(small_pos.count(i)){
            small_pos.erase(i);
            now += a[i];
        }
    }
}
void update(int i) {
    if(big(i)) {
        if(!big_pos.count(i)){
            big_pos.insert(i);
            now += a[i];
        }
    } else if(small(i)){
        if(!small_pos.count(i)){
            small_pos.insert(i);
            now -= a[i];
        }
    }
}
void solve() {
    int n, q;
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    a[0] = a[n + 1] = 0;
    now = 0;
    big_pos.clear();
    small_pos.clear();
    for(int i = 1; i <= n; i++) {
        update(i);
    }
    printf("%lld\n", now);
    while(q--) {
        int l, r;
        scanf("%d%d", &l, &r);
        clear(l-1);
        clear(l);
        clear(l+1);
        clear(r-1);
        clear(r);
        clear(r+1);
        swap(a[l], a[r]);
        update(l-1);
        update(l);
        update(l+1);
        update(r-1);
        update(r);
        update(r+1);
        printf("%lld\n", now);
    }
}
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        solve();
    }
    return 0;
}