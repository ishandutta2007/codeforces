#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005
long long n;
pair<long long, long long> pos[MAXN];

struct FenwickTree {
    vector<long long> bit;  // binary indexed tree
    long long n;
    FenwickTree(long long n) {
        this->n = n;
        bit.assign(n, 0);
    }
    FenwickTree(vector<long long> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }
    long long sum(long long r) {
        long long ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }
    long long sum(long long l, long long r) {
        return sum(r) - sum(l - 1);
    }
    void add(long long idx, long long delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

int main(){
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(long long i = 0; i<n; i++){
        long long a; cin >> a;
        pos[i].first = a;
    }
    pair<long long, long long> temp[n];
    for(long long i = 0; i<n; i++){
        long long a; cin >> a;
        temp[i] = {a, i};
    }
    sort(temp, temp+n);
    long long prev = -100000005;
    long long cur = -1;
    for(long long i = 0; i<n; i++){
        if(temp[i].first != prev) cur++;
        pos[temp[i].second].second = cur;
        prev = temp[i].first;
    }
    sort(pos, pos+n);
    FenwickTree f1(MAXN);
    FenwickTree f2(MAXN);
    long long ans = 0;
    for(long long i = 0; i<n; i++){
        ans -= f1.sum(0, pos[i].second);
        ans += f2.sum(0, pos[i].second)*pos[i].first;
        f1.add(pos[i].second, pos[i].first);
        f2.add(pos[i].second, 1);
    }
    cout << ans << endl;
}