#include<bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define MP make_pair
#define PB emplace_back
using namespace std;
int get_bit(int x,int v){return (x>>v)&1;}
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        int cnt[30] = {};
        while(n--){
            int x;
            scanf("%d", &x);
            for(int i = 29; i >= 0; i--) {
                if(get_bit(x, i)) {
                    cnt[i]++;
                    break;
                }
            }
        }
        long long an = 0;
        for(int i = 0; i < 30; i++) {
            an += cnt[i] * (cnt[i] - 1LL) / 2;
        }
        printf("%lld\n", an);
    }
    return 0;
}