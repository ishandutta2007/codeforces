#include<bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define MP make_pair
#define PB emplace_back
using namespace std;
int a[51];
void solve() {
    int N;
    scanf("%d", &N);
    int l_most = N + 1;
    int r_most = 0;
    int one_cnt = 0;
    for(int i = 1; i <= N; i++) {
        scanf("%d", &a[i]);
        if(a[i]){
            one_cnt++;
            r_most = i;
            if(l_most == N + 1) {
                l_most = i;
            }
        }
    }
    printf("%d\n", r_most - l_most + 1 - one_cnt);
}
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        solve();
    }
    return 0;
}