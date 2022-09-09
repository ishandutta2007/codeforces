#include<bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define MP make_pair
#define PB emplace_back
using namespace std;
void solve() {
    int d, k;
    scanf("%d%d", &d, &k);
    long long now = 0;
    while((now + k) * (now + k) * 2 <= (long long)d * d) { now += k; }
    if((now + k) * (now + k) + now * now <= (long long)d * d) { puts("Ashish"); }
    else { puts("Utkarsh"); }
}
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        solve();
    }
    return 0;
}