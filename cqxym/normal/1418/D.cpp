#include<iostream>
#include<set>
#include<map>
typedef unsigned int u32;
typedef int i32;
typedef unsigned long long int u64;
typedef long long int i64;
using namespace std;
i64 n, m;
set<i64> q;
set<pair<i64, i64>, greater<pair<i64, i64>>> d;
i64 solve() {
    if (q.size() <= 2) {
        return 0;
    }
    return *q.rbegin() - *q.begin() - d.begin()->first;
}
 
int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(15); cout.setf(ios::fixed); cerr.precision(15); cerr.setf(ios::fixed);
 
    cin >> n >> m;
 
    for (i64 i = 0; i < n; i++) {
        i64 t;
        cin >> t;
        q.insert(t);
    }
 
 
    for (auto it = q.begin(); it != q.end(); it++) {
        auto nit = it;
        nit++;
        if (nit == q.end()) {
            break;
        }
        d.insert({ *nit - *it, *nit });
    }
 
    cout << solve() << endl;
 
    for (i64 i = 0; i < m; i++) {
        i64 t, v;
        cin >> t >> v;
        if (t == 0) {
 
            auto it = q.find(v);
            if (it != q.begin()) {
                auto pit = it;
                pit--;
                d.erase({*it - *pit, *it});
            }
 
            auto nit = it;
            nit++;
            if (nit != q.end()) {
                d.erase({ *nit - *it, *nit });
            }
            if (nit != q.end() && it != q.begin()) {
                auto pit = it;
                pit--;
                d.insert({ *nit - *pit, *nit });
            }
            q.erase(v);
        }
        else {
            auto it = q.insert(v).first;
            auto nit = it;
            nit++;
            if (nit != q.end() && it != q.begin()) {
                auto pit = it;
                pit--;
                d.erase({ *nit - *pit, *nit });
            }
            if (it != q.begin()) {
                auto pit = it;
                pit--;
                d.insert({ *it - *pit, *it });
            }
            if (nit != q.end()) {
                d.insert({ *nit - *it, *nit });
            }
        }
        cout << solve() << endl;
    }
    return 0;
}