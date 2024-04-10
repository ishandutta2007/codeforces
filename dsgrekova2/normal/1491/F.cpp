#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#define all(x) (x).begin(), (x).end()
#define ll long long
#define int ll
using namespace std;
bool zapr(vector<int> a, vector<int> b){
    cout << "? " << a.size() << ' ' << b.size() << '\n';
    for (auto i : a)
        cout << i << ' ';
    cout << '\n';
    for (auto i : b)
        cout << i << ' ';
    cout << endl;
    int t;
    cin >> t;
    return t;
}
void solve(){
    int n;
    cin >> n;
    vector<int> good = {1};
    for (int i = 2; i <= n; ++i) {
        if (zapr(good, {i})){
            break;
        }
        good.push_back(i);
    }
    int num = good.size() + 1;
    vector<int> ans;
    int l = -1, r = good.size();
    while (r - l > 1){
        int m = (l + r) / 2;
        vector<int> z1;
        for (int i = 0; i <= m; ++i) {
            z1.push_back(i + 1);
        }
        if (zapr(z1, {num})){
            r = m;
        } else{
            l = m;
        }
    }
    for (auto i : good) {
        if (i != r + 1){
            ans.push_back(i);
        }
    }
    for (int i = num + 1; i <= n; ++i) {
        if (!zapr({i}, {num})){
            ans.push_back(i);
        }
    }
    cout << "! " << ans.size() << ' ';
    for (auto i : ans)
        cout << i << ' ';
    return;
}
signed main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}