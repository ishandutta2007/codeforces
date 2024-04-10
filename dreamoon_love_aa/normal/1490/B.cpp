#include<bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define MP make_pair
#define PB emplace_back
using namespace std;
void solve() {
    int n;
    scanf("%d", &n);
    int cnt[3] = {};
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        cnt[x % 3]++;
    }
    int answer = 0;
    while(1){
        bool done = 1;
        for(int i = 0; i < 3; i++) {
            if(cnt[i] > n / 3) {
                answer += cnt[i] - n / 3;
                cnt[(i + 1) % 3] += cnt[i] - n / 3;
                cnt[i] = n / 3;
                done = 0;
            }
        }
        if(done) { break; }
    }
    printf("%d\n", answer);
}
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        solve();
    }
    return 0;
}