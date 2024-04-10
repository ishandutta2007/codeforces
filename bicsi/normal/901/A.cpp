#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n; ++n;
    vector<int> V(n);
    for (int i = 0; i < n; ++i) {
        cin >> V[i];
    }

    for (int i = 1; i < n; ++i) {
        if (V[i] > 1 && V[i - 1] > 1) {
            cout << "ambiguous" << endl;

            vector<int> last(n);
            int at = 1;


            vector<int> A, B;

            A.push_back(0);
            B.push_back(0);

            last[0] = 1;

            vector<int> nodes_up;

            for (int j = 1; j < n; ++j) {
//                cerr << "j = " << j << endl;
//                cerr << "A[j] = " << V[j] << endl;
                for (int k = 0; k < V[j]; ++k) {
//                    cerr << "k = " << k << endl;
                    A.push_back(last[j - 1]);
                    if (j != i) {
                        B.push_back(last[j - 1]);
                    } else {
                        B.push_back(nodes_up[k % nodes_up.size()]);
                    }
                    last[j] = ++at;
                    if (j == i - 1) nodes_up.push_back(at);
                }
            }

            for (auto x : A) cout << x << " "; cout << endl;
            for (auto x : B) cout << x << " "; cout << endl;

            return 0;
        }
    }

    cout << "perfect" << endl;

    return 0;
}