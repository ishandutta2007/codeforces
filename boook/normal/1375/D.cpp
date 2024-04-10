// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int>
#define F first
#define S second
#define endl "\n"
//--------------------------------------
#define maxn 1100
#define inf 0x3f3f3f3f

int t, n, x[maxn], c[maxn];

int check() {
    for (int i = 1; i < n; ++ i) {
        if (x[i - 1] <= x[i]);
        else return 0;
    } return 1;
}
int32_t main(){
	cin.tie(0), cout.sync_with_stdio(0);
//    cout << "endl;";
	cin >> t;
    while (t --) {
        cin >> n;
        for (int i = 0; i < n; ++ i) c[i] = 0;
        for (int i = 0; i < n; ++ i) cin >> x[i], c[x[i]] ++;
        vector<int> ans;
        int nn = n - 1;
//        cout << "here" << endl;
        while (check() == 0) {
            int base = 0;
            while (c[base]) base ++;
            if (base > nn) {
                ans.emplace_back(nn);
                c[x[nn]] --;
                x[nn] = base;
                c[x[nn]] ++;
                nn--;
            }
            else {
                ans.emplace_back(base);
                c[x[base]] --;
                x[base] = base;
                c[x[base]] ++;
            }
//            for (int i = 0; i < n; ++ i) cout << x[i] << " "; cout << endl;
        }

        cout << ans.size() << "\n";
        for (int i = 0; i < ans.size(); ++ i) {
            cout << ans[i] + 1;
            if (i + 1 != ans.size()) cout << " ";
        } cout << endl;
    }
    return 0;
}