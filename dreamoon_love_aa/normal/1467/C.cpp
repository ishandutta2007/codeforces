#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cmath>
#define SZ(X) ((int)(X).size())
#define MP make_pair
#define PB emplace_back
using namespace std;
int num[3];
vector<long long> d[3];
long long s[3];
void solve() {
    long long sum = 0;
    for(int i = 0; i < 3; i++) {
        cin >> num[i];
    }
    for(int i = 0; i < 3; i++) {
        d[i].resize(num[i]);
        for(auto &x: d[i]) {
            cin >> x;
            sum += x;
            s[i] += x;
        }
        sort(d[i].begin(), d[i].end());
    }
    long long an = 0;
    for(int i = 0; i < 3; i++) {
        an = max(an, sum - s[i] * 2);
    }
    an = max(an, sum - (d[0][0] + d[1][0]) * 2);
    an = max(an, sum - (d[0][0] + d[2][0]) * 2);
    an = max(an, sum - (d[2][0] + d[1][0]) * 2);
    cout << an << endl;
}
int main() {
    solve();
    return 0;
}