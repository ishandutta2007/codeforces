#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t; cin >> t;

    for (int i = 0; i < t; ++i) {
        int a, b; cin >> a >> b;
        string s; cin >> s;
        
        vector<int> sizes;
        auto push = [&](int x) {
            if (x < b) return;
            sizes.push_back(x);
        };

        int cur_size = 0;
        for (int i = 0; i < (int)s.size(); ++i) {
            if (s[i] == 'X') {
                push(cur_size);
                cur_size = 0;    
            } else {
                cur_size += 1;
            }
        }
        push(cur_size);

        sort(sizes.begin(), sizes.end());
        assert(sizes.empty() || sizes[0] >= b);

        if (sizes.empty() || sizes[0] < a) {
            cout << "NO" << '\n';
        } else {
            if (sizes.back() < 2 * b) {
                if (sizes.size() % 2 == 0) {
                    cout << "NO" << '\n';
                } else {
                    cout << "YES" << '\n';
                }
            } else {
                if (sizes.size() >= 2 && sizes[sizes.size() - 2] >= 2 * b) {
                    cout << "NO" << '\n';
                } else {
                    
                    int now = sizes.back();
                    bool can_win = false;
                    for (int i = 0, j = now - a; j >= 0; ++i, --j) {
                        if (i >= 2 * b || j >= 2 * b) continue;
                        if (i >= b && i < a) continue;
                        if (j >= b && j < a) continue;

                        int moves = sizes.size();
                        if (i >= a) moves += 1;
                        if (j >= a) moves += 1;
                        if (moves % 2 == 1) {
                            can_win = true;
                            break;
                        }
                    }
                    
                    if (can_win) {
                        cout << "YES" << '\n';
                    } else {
                        cout << "NO" << '\n';
                    }
                }
            }
        }

    }


    return 0;
}