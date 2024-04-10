#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005
long long n, k;

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
    cin >> n >> k;
    long long arr[n];
    for(long long i = 0; i<n; i++) cin >> arr[i];
    sort(arr, arr+n);
    map<long long, long long> pos;
    map<long long, long long> num;
    long long cur = 0;
    long long prev = arr[0];
    FenwickTree f(MAXN);
    FenwickTree ff(MAXN);
    for(long long i = 0; i<n; i++){
        if(arr[i] != prev) cur++;
        pos[arr[i]] = cur;
        f.add(cur, arr[i]);
        ff.add(cur, 1);
        num[arr[i]]++;
        prev = arr[i];
    }
    long long ans = 10000000000000000;
    for(long long i = 0; i<n; i++){
        if(num[arr[i]] >= k){
            cout << 0 << endl;
            exit(0);
        }
        long long sum1 = f.sum(pos[arr[i]]+1, MAXN-1)-ff.sum(pos[arr[i]]+1, MAXN-1)*(arr[i]+1);
        long long sum2 = ff.sum(0, pos[arr[i]]-1)*(arr[i]-1)-f.sum(0, pos[arr[i]]-1);
        if(ff.sum(pos[arr[i]], MAXN-1) >= k){
            ans = min(ans, sum1+k-num[arr[i]]);
        }
        if(ff.sum(0, pos[arr[i]]) >= k){
            ans = min(ans, sum2+k-num[arr[i]]);
        }
        ans = min(ans, sum1+sum2+k-num[arr[i]]);
    }
    cout << ans << endl;
}