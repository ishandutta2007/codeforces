#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file
#else

#endif



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Togliere nei problemi con query online

    int n, m;
    cin >> n >> m;
    vector<int> s(m+1), h(m+1);
    vector<int> c(n);
    //~ cout << m << endl;
    for (int i = 1; i <= m; i++) {
        cin >> s[i] >> h[i];
        s[i]--;
        c[s[i]] = i;
    }
    //~ for (int i = 0; i < n; i++) cout << i << " "  << c[i] << endl;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        vector<int> ord;
        bool poss = true;
        int at = -1;
        for (int j = n-1; j > i; j--) {
            if (c[j]) {
                if (h[c[j]] > at) {
                    at = h[c[j]];
                    ord.push_back(c[j]);
                }
                else {
                    int x = ord.back();
                    ord.pop_back();
                    ord.push_back(c[j]);
                    ord.push_back(x);
                }
            }
            if (at == -1) continue;
            at += a[j];
            if (at < 0) {
                poss = false;
                break;
            }
        }
        at = -1;
        bool sx = false;
        for (int j = 0; j <= i; j++) {
            if (c[j]) {
                sx = true;
                if (h[c[j]] > at) {
                    at = h[c[j]];
                    ord.push_back(c[j]);
                }
                else {
                    int x = ord.back();
                    ord.pop_back();
                    ord.push_back(c[j]);
                    ord.push_back(x);
                }
            }
            if (at == -1) continue;
            at += a[j];
            if (at < 0) {
                poss = false;
                break;
            }
        }
        if (poss and sx) {
            cout << i+1 << "\n";
            reverse(ord.begin(), ord.end());
            for (int x : ord) cout << x << " ";
            cout << "\n";
            return 0;
        }
        else if (poss) {
            cout << i+2 << "\n";
            reverse(ord.begin(), ord.end());
            for (int x : ord) cout << x << " ";
            cout << "\n";
            return 0;
        }
    }
    cout << -1 << "\n";
}