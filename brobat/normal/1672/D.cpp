#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;
// #define int long long

#define vector deque

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector <int> a(n), b(n);

        vector<vector<int>> v(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            --a[i];
            v[a[i]].push_back(i);
        }
        for(int i = 0; i < n; i++) {
            cin >> b[i];
            --b[i];
        }

        // set <int> s;
        // for(int i = 0; i < n; i++) {
        //     s.insert(i);
        // }

        // bool pos = true;

        // if(a[n - 1] != b[n - 1]) {
        //     cout << "NO\n";
        //     continue;
        // }
        // s.erase(n - 1);
        // // int prev = a[n - 1];
        // v[a[n - 1]].pop_back();

        // for(int i = n - 2; i >= 0; i--) {
        //     // see if we can make b[i].
        //     if(b[i] == b[i + 1]) {
        //         // cout << "hm" << '\n';
        //         int x = v[b[i]].size();
        //         if(x == 0) {
        //             pos = false; break;
        //         }
        //         int last = v[b[i]][x - 1];
        //         s.erase(last);
        //         v[b[i]].pop_back();
        //     } else {
        //         int last = *(--s.end());
        //         if(a[last] != b[i]) {
        //             pos = false;
        //             break;
        //         } else {
        //             // int prev = a[last];
        //             if(v[a[last]].size() == 0) {
        //                 pos = false;
        //                 break;
        //             }
        //             s.erase(last);
        //             v[a[last]].pop_back();
        //         }
        //     }
        // }


        vector <int> cnt(n, 1);
        bool pos = true;
        int prev_index = 0;

        for(int i = 0; i < n; i++) {
            if(!pos) break;
            int needed = b[i];
            if((int)v[needed].size() == 0) {
                pos = false; break;
            }
            int index = v[needed][0];
            vector <int> pls;
            for(int j = max(prev_index, i); j < index; j++) {
                if(cnt[j] == 0) continue;
                int value = a[j];
                if((int)v[value].size() <= 1) {
                    pos = false; break;
                }
                v[value].pop_front();
                cnt[v[value][0]] += cnt[j];
                cnt[j] = 0;
            }
            cnt[index]--;
            if(cnt[index] == 0) {
                v[needed].pop_front();
            }
            prev_index = index;
        }
        cout << (pos ? "YES" : "NO") << '\n';
    }
    
    return 0;
}