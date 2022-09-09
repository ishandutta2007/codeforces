#include<iostream>
#include<algorithm>
using namespace std;
int d[1000000][5];
int n;
bool cmp(int x, int y){
    int cnt=0;
    for(int i = 0; i < 5; i++) {
        cnt+=(d[x][i]<d[y][i])*2-1;
    }
    return cnt < 0;
}
int id[1000000];
void solve() {
    for(int i = 0; i < n; i++) id[i] = i;
    sort(id, id + n, cmp);
    for(int i = 0; i < n - 1; i++) {
        if(!cmp(id[i], id[n - 1])) {
            cout << -1 << '\n';
            return;
        }
    }
    cout << id[n - 1] + 1 << '\n';
}
void input() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 5; j++) {
            cin >> d[i][j];
        }
    }
}
int main() {
    int T;
    cin >> T;
    while(T--) {
        input();
        solve();
    }
    return 0;
}