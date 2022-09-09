#include<bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define MP make_pair
#define PB emplace_back
using namespace std;
const int SIZE = 5010;
int a[SIZE];
void solve() {
    int N;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) {
        scanf("%d", &a[i]);
    }
    if(count(a + 1, a + N + 1, a[1]) == N) {
        puts("NO");
        return;
    }
    puts("YES");
    int lat = -1;
    for(int i = 2; i <= N; i++) {
        if(a[i] != a[1]) {
            printf("1 %d\n", i);
            lat = i;
        }
    }
    for(int i = 2; i <= N; i++) {
        if(a[i] == a[1]) {
            printf("%d %d\n", lat, i);
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