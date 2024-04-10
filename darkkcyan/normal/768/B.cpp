#include <bits/stdc++.h>

using namespace std;

#define long long long 
#define ve vector
#define vi ve<int>
#define ii pair<int, int>
#define xx first
#define yy second
#define sz(v) ((int)v.size())
#define inf(t) numeric_limits<t>::max()

long n, l, r;

map<long, long> len, cnt;

long getlen(long num) {
    if (len.count(num)) return len[num];
    else return len[num] = 1 + 2 * getlen(num / 2);
}

long getcnt(long num) {
    if (cnt.count(num)) return cnt[num];
    else return cnt[num] = num % 2 + getcnt(num / 2) * 2;
}

long count(long num, long pos) {
    if (pos < 0) return 0;
    if (num == 0 or num == 1) return num;
    long l = getlen(num);
    long ans = 0;
    if (pos >= l / 2) {
        ans += getcnt(num / 2) + num % 2;
        pos -= l / 2 + 1;
    }
    ans += count(num / 2, pos);
    return ans;
}


int main() {
#ifndef ONLINE_JUDGE 
    freopen("in.txt", "r", stdin);
    freopen("ou.txt", "w", stdout);
#endif

    cin >> n >> l >> r; --l, --r;
    len[0] = len[1] = 1;
    cnt[0] = 0, cnt[1] = 1;

    cout << count(n, r) - count(n, l - 1);

    return 0;
}