#include<bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define MP make_pair
#define PB emplace_back
using namespace std;
bool valid(int now, int k, int x) {
    int v = now - x;
    return v != 1 && v != (2LL + k + 1) * k / 2 - 1 && v <= (2LL + k + 1) * k / 2;
}
void solve() {
    int x;
    scanf("%d", &x);
    int now = 1;
    int k = 1;
    while(now < x) {
        k++;
        now+=k;
    }
    while(!valid(now, k, x)) {
        k++;
        now += k;
    }
    printf("%d\n", k);
}
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        solve();
    }
    return 0;
}