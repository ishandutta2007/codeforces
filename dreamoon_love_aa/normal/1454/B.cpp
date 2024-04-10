#include<bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define MP make_pair
#define PB emplace_back
using namespace std;
const int SIZE = 2e5+5;
int pos[SIZE];
int cnt[SIZE];
void solve() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i<= n; i++) {
        cnt[i] = 0;
        pos[i] = 0;
    }
    for(int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        pos[x] = i;
        cnt[x]++;
    }
    for(int i = 1; i <= n; i++) {
        if(cnt[i] == 1) {
            printf("%d\n", pos[i]);
            return;
        }
    }
    puts("-1");
}
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        solve();
    }
    return 0;
}