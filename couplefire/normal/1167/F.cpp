#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define MAXN 500005

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
    cin.tie(NULL);
    long long n; cin >> n;
    pair<long long, long long> arr[n];
    for(long long i = 0; i<n; i++){
        long long a; cin >> a;
        arr[i] = {a, i};
    }
    sort(arr, arr+n);
    FenwickTree BIT1(MAXN); //greater
    FenwickTree BIT2(MAXN); //smaller
    long long ans = 0;
    for(long long i = 0; i<n; i++){
        ans += (BIT1.sum(arr[i].second, MAXN-1)*(arr[i].second+1)%MOD)*arr[i].first;
        ans %= MOD;
        ans += (BIT2.sum(0, arr[i].second)*(n-arr[i].second)%MOD)*arr[i].first;
        ans %= MOD;
        ans += ((arr[i].second+1)*(n-arr[i].second)%MOD)*arr[i].first;
        ans %= MOD;
        BIT1.add(arr[i].second, n-arr[i].second);
        BIT2.add(arr[i].second, arr[i].second+1);
    }
    cout << ans << endl;
}