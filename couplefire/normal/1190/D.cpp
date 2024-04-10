#include <bits/stdc++.h>
using namespace std;
#define MAXN 200010

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

FenwickTree BIT(MAXN);

int main(){
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n; cin >> n;
    vector<pair<long long, long long>> v(n);
    map<long long, vector<long long>, greater<long long>> mp;
    for(long long i = 0; i<n; i++){
        long long a, b; cin >> a >> b;
        v[i] = {a, b};
    }
    sort(v.begin(), v.end());
    long long cur = 1;
    long long prev = -1;
    for(long long i = 0; i<n; i++){
        if(v[i].first == prev){
            prev = v[i].first;
            v[i] = {cur, v[i].second};
        }
        else{
            prev = v[i].first;
            v[i] = {++cur, v[i].second};
        }
        mp[v[i].second].push_back(v[i].first);
    }
    // for(auto i:mp){
    //     for(auto j : i.second){
    //         cout << i.first << " " << j << endl;
    //     }
    // }
    long long ans = 0;
    for(auto i : mp){
        long long y = i.first;
        vector<long long> st = i.second;
        sort(st.begin(), st.end());
        st.erase(unique(st.begin(), st.end()), st.end());
        for(auto j : st){
            //cout << y << " " << j << endl;
            if(BIT.sum(j, j) == 0) BIT.add(j, 1);
        }
        long long total = BIT.sum(0, MAXN-1);
        ans += total*(total+1)/2;
        for(long long j = 1; j<st.size(); j++){
            long long temp = BIT.sum(st[j-1]+1, st[j]-1);
            ans -= temp*(temp+1)/2;
        }
        long long t = BIT.sum(0, st[0]-1);
        long long tt = BIT.sum(st[st.size()-1]+1, MAXN-1);
        ans -= t*(t+1)/2;
        ans -= tt*(tt+1)/2;
    }
    cout << ans << endl;
}