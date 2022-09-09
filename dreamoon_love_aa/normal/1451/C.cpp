#include<bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define MP make_pair
#define PB emplace_back
using namespace std;
const int SIZE = 1 << 20;
char a[SIZE], b[SIZE];
void solve() {
    int n, k;
    scanf("%d%d", &n, &k);
    scanf("%s", a);
    scanf("%s", b);
    int cnt_a[26] = {};
    int cnt_b[26] = {};
    for(int i = 0; i < n; i++) {
        cnt_a[a[i] - 'a']++;
        cnt_b[b[i] - 'a']++;
    }
    for(int i = 0;i < 25; i++) {
        if(cnt_a[i] < cnt_b[i] || (cnt_a[i] - cnt_b[i]) % k) {
            printf("No\n");
            return;
        }
        cnt_a[i + 1] += cnt_a[i] - cnt_b[i];
    }
    puts("Yes");
}
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        solve();
    }
    return 0;
}