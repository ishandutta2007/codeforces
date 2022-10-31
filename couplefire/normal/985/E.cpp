#include <bits/stdc++.h>
using namespace std;

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
    long long n, k, d; cin >> n >> k >> d;
    long long arr[n];
    for(long long i = 0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    FenwickTree f(n);
    long long newarr[n];
    for(long long i = 0; i<n; i++){
        newarr[i] = lower_bound(arr, arr+n, arr[i]-d)-arr;
    }
    long long dp[n];
    fill(dp, dp+n, 0);
    for(long long i = 0; i<n; i++){
        if(i-newarr[i]+1 < k) continue;
        if(i+1 >= k && newarr[i] == 0){
            dp[i] = 1;
            f.add(i, 1);
            continue;
        }
        if(f.sum(newarr[i]-1, i-k) > 0) dp[i] = 1;
        f.add(i, dp[i]);
    }
    if(dp[n-1]){
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;
}