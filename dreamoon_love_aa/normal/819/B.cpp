#include<iostream>
#include<algorithm>
using namespace std;
const int SIZE = 1 << 20;
int change_sign[SIZE][2];
int change_val[SIZE];
void solve() {
    int n;
    cin >> n;
    long long now = 0;
    int add_num = 0;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        now += abs(x - i);
        if(x <= i) add_num++;
        change_sign[(x - i + n) % n][0]++;
        change_sign[n - i + 1][1]++;
        change_val[n - i + 1] += (x - 1) - (n - x);
    }
    long long an = now;
    int an2 = 0;
    for(int i = 1; i < n; i++) {
        now += add_num - change_sign[i][1];
        now -= n - add_num;
        now += change_val[i];
        if(an > now) {
            an = now;
            an2 = i;
        }
        add_num += change_sign[i][0] - change_sign[i][1];
    }
    cout << an << ' ' << an2 << '\n';
}
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}