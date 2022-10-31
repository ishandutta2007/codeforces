#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

inline int add(int a, int b){return (a+b>=MOD)?a+b-MOD:a+b;}
inline void inc(int& a, int b){a = add(a, b);}
inline int sub(int a, int b){return (a-b<0)?a-b+MOD:a-b;}
inline void dec(int &a, int b){a = sub(a, b);}
inline int mul(int a, int b){return 1ll*a*b%MOD;}
inline void grow(int &a, int b){a = mul(a, b);}

struct FenwickSum{
    vector<int> bit;
    int n;
    FenwickSum(){}
    FenwickSum(int n) {
        this->n = n;
        bit.assign(n, 0);
    }
    FenwickSum(vector<int> a) : FenwickSum(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }
    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            inc(ret, bit[r]);
        return ret;
    }
    int sum(int l, int r) {
        return sub(sum(r), sum(l - 1));
    }
    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            inc(bit[idx], delta);
    }
};

struct FenwickMax{
    vector<int> bit;
    int n;
    FenwickMax(){}
    FenwickMax(int n) {
        this->n = n;
        bit.assign(n, -MOD);
    }

    FenwickMax(vector<int> a) : FenwickMax(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            update(i, a[i]);
    }

    int getMax(int r) {
        int ret = -MOD;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret = max(ret, bit[r]);
        return ret;
    }

    void update(int idx, int val) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] = max(bit[idx], val);
    }
};

void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i<n; ++i)
        cin >> arr[i];
    vector<int> tmp = arr;
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    map<int, int> id;
    for(int i = 0; i<(int)tmp.size(); ++i)
        id[tmp[i]] = i;
    for(auto& x : arr) x = id[x];
    FenwickSum tree1(n);
    vector<int> ldp(n);
    for(int i = 0; i<n; ++i){
        ldp[i] = add(tree1.sum(arr[i]-1), 1);
        tree1.add(arr[i], ldp[i]);
    }
    vector<int> top(n);
    FenwickMax tree2(n);
    for(int i = n-1; i>=0; --i){
        top[i] = tree2.getMax(n-1-arr[i]-1);
        if(top[i]==-MOD) top[i] = n;
        tree2.update(n-1-arr[i], i);
    }
    vector<vector<int>> stuff(n);
    for(int i = 0; i<n; ++i)
        if(top[i]<n) stuff[top[i]].push_back(i);
    tree1 = FenwickSum(n);
    vector<int> rdp1(n), rdp2(n);
    for(int i = n-1; i>=0; --i){
        rdp1[i] = add(tree1.sum(arr[i]+1, n-1), 1);
        tree1.add(arr[i], rdp1[i]);
    }
    tree1 = FenwickSum(n);
    for(int i = 0; i<n; ++i){
        vector<int>& tmp = stuff[i];
        int m = tmp.size();
        for(int j = m-1; j>=0; --j){
            rdp2[tmp[j]] = add(tree1.sum(arr[tmp[j]]+1, n-1), 1);
            tree1.add(arr[tmp[j]], rdp2[tmp[j]]);
        }
        for(auto x : tmp) tree1.add(arr[x], MOD-tree1.sum(arr[x], arr[x]));
    }
    int ans = 0;
    for(int i = 0; i<n; ++i)
        if(top[i]<n) inc(ans, mul(ldp[i], sub(rdp1[i], rdp2[i])));
    cout << ans << '\n';
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}