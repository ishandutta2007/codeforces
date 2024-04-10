#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

vector<string> T(vector<string> mat) {
    int n = mat.size(), m = mat[0].size();
    vector<string> ret(m, string(n, '.'));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            ret[j][i] = mat[i][j];
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<string> mat(n);
    for (int i = 0; i < n; ++i) {
        cin >> mat[i];
    }
       
    int btbest = -1;
    vector<string> bsol;

    string sigma = "ACGT";
    sort(sigma.begin(), sigma.end());
    do {
        vector<string> sol;
        int tbest = 0;
        for (int i = 0; i < n; ++i) {
            char a = sigma[(i % 2) * 2];
            char b = sigma[(i % 2) * 2 + 1];
            
            int best = -1;
            string bstr;

            for (int it = 0; it < 2; ++it) {
                int total = 0;
                string now = "";
                for (int j = 0; j < m; ++j) {
                    now += (j % 2) ? a : b;
                    if (now[j] == mat[i][j])
                        total += 1;
                }
                if (total > best) {
                    best = total;
                    bstr = now;
                }
                swap(a, b);
            }
            
            sol.push_back(bstr);
            tbest += best;
        }
        if (btbest < tbest) {
            btbest = tbest;
            bsol = sol;
        }
        
        sol.clear();
        tbest = 0;
        
        for (int i = 0; i < m; ++i) {
            char a = sigma[(i % 2) * 2];
            char b = sigma[(i % 2) * 2 + 1];
            
            int best = -1;
            string bstr;

            for (int it = 0; it < 2; ++it) {
                int total = 0;
                string now = "";
                for (int j = 0; j < n; ++j) {
                    now += (j % 2) ? a : b;
                    if (now[j] == mat[j][i])
                        total += 1;
                }
                if (total > best) {
                    best = total;
                    bstr = now;
                }
                swap(a, b);
            }
            
            sol.push_back(bstr);
            tbest += best;
        }
        if (btbest < tbest) {
            btbest = tbest;
            bsol = T(sol);
        }
    } while (next_permutation(sigma.begin(), sigma.end()));
    
    // cerr << n * m - btbest << endl;    
    for (auto x : bsol)
        cout << x << '\n';
    
    return 0;
}