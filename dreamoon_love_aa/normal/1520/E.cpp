#include<iostream>
#include<algorithm>
using namespace std;
const int SIZE = 1 << 20;
int change_cnt[SIZE];
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int num = 0;
    long long now = 0;
    int add_cnt = 0;
    for(int i = 1; i <= n; i++) change_cnt[i] = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '*') {
            now += abs(i - num);
            change_cnt[i - num + 1]++;
            num++;
        }
    }
    long long an = now;
    for(int i = 1; i + num <= n; i++) {
        add_cnt += change_cnt[i];
        now += add_cnt - (num - add_cnt);
        an = min(an, now);
    }
    cout << an << '\n';
}
int main() {
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}