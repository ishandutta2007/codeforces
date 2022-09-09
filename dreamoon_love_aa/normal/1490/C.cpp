#include<bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define MP make_pair
#define PB emplace_back
using namespace std;
set<long long> cube;
void pre(){
    for(int i = 1; i <= 10000; i++) { cube.insert((long long)i * i * i); }
}
void solve() {
    long long x;
    scanf("%lld", &x);
    bool found = 0;
    for(long long i = 1; i <= 10000; i++) {
        if(cube.count(x - i * i * i)) {
            found = 1;
        }
    }
    puts(found ? "YES" : "NO");
}
int main() {
    pre();
    int T;
    scanf("%d", &T);
    while(T--) {
        solve();
    }
    return 0;
}