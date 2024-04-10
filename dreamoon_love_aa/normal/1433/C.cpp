#include<bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define MP make_pair
#define PB emplace_back
using namespace std;
const int SIZE = 300010;
int a[SIZE];
void solve() {
    int N;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) {
        scanf("%d", &a[i]);
    }
    int ma = *max_element(a + 1, a + N + 1);
    if(count(a + 1, a + N + 1, ma) == N) {
        puts("-1");
    } else {
        for(int i = 1; i <= N; i++) {
            if(i > 1 && a[i] == ma && a[i] > a[i - 1]) {
                printf("%d\n", i);
                return;
            }
            if(i < N && a[i] == ma && a[i] > a[i + 1]) {
                printf("%d\n", i);
                return;
            }
        }
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