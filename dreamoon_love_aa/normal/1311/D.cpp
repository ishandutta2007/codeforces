#include<bits/stdc++.h>
using namespace std;
vector<int>fac[40000];
void pre() {
    for(int i = 1; i < 40000; i++)
        for(int j = i; j < 40000; j += i)fac[j].push_back(i);
}
int solve() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int an = 1e9;
    int A, B, C;
    for(int i = 1; i < b + an; i++) {
        int tA, tC;
        int it = lower_bound(fac[i].begin(), fac[i].end(), a) - fac[i].begin();
        if(it == (int)fac[i].size()) tA = fac[i][it - 1];
        else if(!it) tA = fac[i][0];
        else if(fac[i][it] - a < a - fac[i][it - 1]) tA = fac[i][it];
        else tA = fac[i][it - 1];
        if(c % i < i - c % i) {
            tC = c / i * i;
        }
        else {
            tC = c / i * i + i;
        }
        int need = abs(tA - a) + abs(i - b) + abs(tC - c);
        //printf("[%d,%d]\n",i,need);
        if(need < an) {
            an = need;
            tie(A, B, C) = make_tuple(tA, i, tC);
        }
    }
    printf("%d\n", an);
    printf("%d %d %d\n", A, B, C);
}
int main() {
    pre();
    int T;
    scanf("%d", &T);
    for(int cs = 1; cs <= T; cs++) {
        solve();
    }
    return 0;
}