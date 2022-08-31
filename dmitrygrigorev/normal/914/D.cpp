#include <bits/stdc++.h>
#define int long long
using namespace std;
int gcd(int a, int b){
    if (b == 0) return a;
    return gcd(b, a%b);
}
vector<int> v;
vector<int> rmq, nums, ls, rs;
void create(int i, int l, int r){
    if (r - l ==1){
        rmq[i] = v[l];
        return;
    }
    int mid = (l+r) / 2;
    create(2*i+1, l, mid);
    create(2*i+2, mid, r);
    rmq[i] = gcd(rmq[2*i+1], rmq[2*i+2]);
}
void change(int i, int l, int r, int ind, int W){
    if (r - l ==1){
        rmq[i] = W;
        return;
    }
    int mid = (l+r) / 2;
    if (ind < mid) change(2*i+1, l, mid, ind, W);
    else change (2*i+2, mid, r, ind, W);
    rmq[i] = gcd(rmq[2*i+1], rmq[2*i+2]);
}
void get(int i, int l, int r, int l1, int r1, int W){
    if (l1 >= r1) return;
    if (l == l1 && r == r1){
        if (rmq[i] % W != 0){
            nums.push_back(i);
            ls.push_back(l);
            rs.push_back(r);
        }
        return;
    }
    int mid = (l+r) / 2;
    get(2*i+1, l, mid, l1, min(r1, mid), W);
    get(2*i+2, mid, r, max(l1, mid), r1, W);
}
bool work(int i, int l, int r, int W){
    if (r - l == 1) return true;
    bool A = (rmq[2*i+1] % W != 0);
    bool B = (rmq[2*i+2] % W != 0);
    if (A && B) return false;
    int mid = (l+r) / 2;
    if (A) return  work(2*i+1, l, mid, W);
    return work(2*i+2, mid, r, W);
}
signed main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i=0; i < n; i++){
        int A;
        cin >> A;
        v.push_back(A);
    }
    for (int i=0; i < 4*n; i++){
        rmq.push_back(0);
    }
    create(0, 0, n);
    int q;
    cin >> q;
    for (int i=0; i < q; i++){
        int t;
        cin >> t;
        if (t == 2){
            int w, Y;
            cin >> w >> Y;
            change(0, 0, n, w-1, Y);
        }
        else{
            int L, R, X;
            cin >> L >> R >> X;
            nums.clear();
            ls.clear();
            rs.clear();
            get(0, 0, n, L-1, R, X);
            if (nums.size() == 0) cout << "YES" << "\n";
            else if (nums.size() > 1) cout << "NO" << "\n";
            else if (work(nums.back(), ls.back(), rs.back(), X)) cout << "YES" << "\n";
            else cout << "NO" << "\n";
        }
    }
    return 0;
}