#include<bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define MP make_pair
#define PB emplace_back
using namespace std;
const int SIZE = 2e5 + 5;
vector<int> pos[SIZE];
void solve() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) { pos[i].clear(); }
    for(int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        pos[x].push_back(i);
    }
    int answer = n;
    for(int i = 1; i <= n; i++) {
        if(pos[i].empty()) { continue; }
        int need = 0;
        if(pos[i][0] > 1) { need++; }
        if(pos[i].back() < n) { need++; }
        for(int j = 1; j < SZ(pos[i]); j++) {
            if(pos[i][j] > pos[i][j - 1] + 1) {
                need++;
            }
        }
        answer = min(answer, need);
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