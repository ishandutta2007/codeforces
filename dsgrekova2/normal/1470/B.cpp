#include "list"
#include <iostream>
#include <utility>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#include "queue"
#include "complex"
#include "cassert"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define EPS 1e-11
typedef long long int ll;
typedef long double ld;
using namespace std;
vector<int> sq;
int nsq(int x){
    int mxs = 1;
    for (int i = 1; i * i * i <= x; ++i) {
        if (x % (i * i) == 0)
            mxs = max(mxs, i * i);
        if (x % i == 0 and sq[x/i])
            mxs = max(mxs, x/i);
    }
    return x / mxs;
}
void sv(){
    int res = 1;
    map<int, int> a;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        t = nsq(t);
        a[t] = a[t] + 1;
        res = max(res, a[t]);
    }
    int q;
    cin >> q;
    int ans3 = 0;
    for (auto i : a){
        if (i.first == 1 or i.second % 2 == 0)
            ans3 += i.second;
    }
    for (int i = 0; i < q; ++i) {
        ll w;
        cin >> w;
        if (w >= 1)
            cout << max(ans3, res) << '\n';
        else
            cout << res << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    sq.assign(1e6 + 5, 0);
    for (int i = 1; i * i <= 1e6; ++i) {
        sq[i * i] = 1;
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        sv();
    }
}