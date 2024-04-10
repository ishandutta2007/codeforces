#include<iostream>
#include<algorithm>
#include<vector>
#define SZ(X) ((int)(X).size())
#define PB push_back
using namespace std;
const int SIZE = 1 << 17;
vector<long long> nums;
void divide(const vector<int> &a) {
    int mi = *min_element(a.begin(), a.end());
    int ma = *max_element(a.begin(), a.end());
    int mm = (mi + ma) / 2;
    vector<int> l, r;
    long long sum = 0;
    for(int x: a) {
        sum += x;
        if(x <= mm) l.PB(x);
        else r.PB(x);
    }
    nums.push_back(sum);
    if(SZ(l) && SZ(r)) {
        divide(l);
        divide(r);
    }
}
int an[SIZE];
void solve() {
    nums.clear();
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    divide(a);
    divide(a);
    sort(nums.begin(), nums.end());
    while(q--) {
        int s;
        cin >> s;
        cout << (binary_search(nums.begin(), nums.end(), s) ? "Yes" : "No") << '\n';
    }
}
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}