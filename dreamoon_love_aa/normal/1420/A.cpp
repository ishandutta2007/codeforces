#include<bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define MP make_pair
#define PB emplace_back
using namespace std;
int main() {
    int T;
    scanf("%d", &T);
    while(T--){
        int n;
        scanf("%d", &n);
        int lt=2e9;
        bool is_yes = 0;
        for(int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            if(x >= lt) {
                is_yes = 1;
            }
            lt = x;
        }
        puts(is_yes ? "YES" : "NO");
    }
    return 0;
}