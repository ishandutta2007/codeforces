#include<bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define MP make_pair
#define PB emplace_back
using namespace std;
const int MAX_N = 40;
bitset<MAX_N>MASK, e[MAX_N], ans;
int N;
void bk_init(){
    for(int i = 0; i < N; i++) { e[i].reset(); }
    ans.reset();
    MASK.set();
}
void bk(bitset<MAX_N> use, bitset<MAX_N> can_start, bitset<MAX_N> can_other){
    if(can_start.none() && can_other.none()){
        if(use.count() > ans.count()) { ans=use; }
        return;
    }
    bitset<MAX_N> r = can_start;
    bitset<MAX_N> AA = can_other | can_start;
    for(int i = 0; i < N; i++) {
        if(AA[i]) {
            r &= ~e[i];
            break;
        }
    }
    for(int i = 0; i < N; i++) {
        if(r[i]){
            use[i] = 1;
            bk(use, can_start & e[i], can_other & e[i]);
            use[i] = 0;
            can_start[i] = 0;
            can_other[i] = 1;
        }
    }
}
void solve_bk(){
    bk(bitset<MAX_N>(), MASK, bitset<MAX_N>());
}
void solve(){
    bk_init();
    int k;
    scanf("%d%d", &N, &k);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) {
            int v;
            scanf("%d", &v);
            e[i][j] = v;
        }
    }
    solve_bk();
    printf("%.12f\n", k * k * (ans.count() - 1) * 0.5 / ans.count());
}
int main(){
    solve();
    return 0;
}