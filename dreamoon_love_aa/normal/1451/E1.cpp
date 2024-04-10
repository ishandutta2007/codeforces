#include<bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define MP make_pair
#define PB emplace_back
using namespace std;
const int OR_OPER = 0;
const int AND_OPER = 1;
const int XOR_OPER = 2;
int query(int oper, int i, int j) {
    if(oper == OR_OPER) { printf("OR"); }
    if(oper == AND_OPER) { printf("AND"); }
    if(oper == XOR_OPER) { printf("XOR"); }
    printf(" %d %d\n", i, j);
    fflush(stdout);
    int ret;
    scanf("%d", &ret);
    return ret;
}
const int SIZE = 1 << 17;
int a[SIZE];
int v[SIZE];
int from[SIZE];
int n;
void print() {
    printf("!");
    for(int i = 1; i <= n; i++) {
        printf(" %d", a[i]);
    }
    puts("");
    fflush(stdout);
}
void do_case1(int i, int j) {
    a[i] = a[j] = query(AND_OPER, i, j);
    a[1] = v[i] ^ a[i];
    for(int k = 2; k <= n; k++) {
        a[k] = a[1] ^ v[k];
    }
    print();
}
int get_bit(int x,int _v){ return (x >> _v) & 1; }
void do_case2(int id1, int id2) {
    int v1 = query(AND_OPER, 1, id1);
    int v2 = query(AND_OPER, 1, id2);
    for(int i = 0; i < 16; i++) {
        int me = 0;
        if(i == 0) {
            me = get_bit(v2, i);
        } else {
            me = get_bit(v1, i);
        }
        a[1] |= me << i;
        for(int j = 2; j <= n; j++) {
            a[j] |= (me ^ get_bit(v[j], i)) << i;
        }
    }
    print();
}
void solve() {
    scanf("%d", &n);
    for(int i = 2; i <= n; i++) {
        v[i] = query(XOR_OPER, 1, i);
    }
    for(int i = 2; i <= n; i++) {
        if(!v[i]) {
            do_case1(1, i);
            return;
        }
    }
    for(int i = 2; i <= n; i++) {
        if(from[v[i]] == 0) {
            from[v[i]] = i;
        } else {
            do_case1(from[v[i]], i);
            return;
        }
    }
    do_case2(from[1], from[2]);
}
int main() {
    solve();
    return 0;
}