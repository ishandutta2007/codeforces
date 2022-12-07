#include <bits/stdc++.h>
using namespace std;
#define int long long

bool comp(deque<char> &a, deque<char> &b) {
    int x = a.size();
    int y = b.size();
    return x < y;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        string s;
        cin >> s;
        int n = s.length();
        vector<deque<char>> v(n);
        int i = 0;
        v[0].push_back(s[0]);
        for(int j = 1; j < n; j++) {
            if(s[j] == s[j - 1]) {
                i++;
            }
            v[i].push_back(s[j]);
        }
        // for(auto i : v) {
        //     for(auto j : i) cout << j;
        //     cout << " ";
        // }
        // cout << '\n';
        int m = v.size();
        sort(v.begin(), v.end(), comp);
        for(int i = 0; i < m; i++) {
            // remove all even AB
            int x = v[i].size();
            if((x == 0) || (x % 2 == 1) || (v[i][0] == 'B')) continue;
            while(c > 0 && x > 0) {
                c--;
                x -= 2;
                v[i].pop_front();
                v[i].pop_front();
            }
        }
        sort(v.begin(), v.end(), comp);
        for(int i = 0; i < m; i++) {
            // remove all even BA
            int x = v[i].size();
            if((x == 0) || (x % 2 == 1) || (v[i][0] == 'A')) continue;
            while(d > 0 && x > 0) {
                d--;
                x -= 2;
                v[i].pop_front();
                v[i].pop_front();
            }
        }
        // for(auto i : v) {
        //     for(auto j : i) cout << j;
        //     cout << " ";
        // }
        // cout << '\n';
        // cout << a << " " << b << " " << c << " " << d << '\n';

        sort(v.begin(), v.end(), comp);
        for(int i = 0; i < m; i++) {
            // remove all odd AB
            int x = v[i].size();
            if((x <= 1) || (x % 2 == 0) || (v[i][0] == 'B')) continue;
            while(c > 0 && x > 1) {
                c--;
                x -= 2;
                v[i].pop_front();
                v[i].pop_front();
            }
        }
        sort(v.begin(), v.end(), comp);
        for(int i = 0; i < m; i++) {
            // remove all odd BA
            int x = v[i].size();
            if((x <= 1) || (x % 2 == 0) || (v[i][0] == 'A')) continue;
            while(d > 0 && x > 1) {
                d--;
                x -= 2;
                v[i].pop_front();
                v[i].pop_front();
            }
        }

        sort(v.begin(), v.end(), comp);
        if(c > 0) {
            for(int i = 0; i < m; i++) {
                int x = v[i].size();
                if(x <= 1) continue;
                if(v[i][0] == 'B') {
                    b--;
                    x--;
                    v[i].pop_front();
                }
                while(c > 0 && x > 1) {
                    c--;
                    x -= 2;
                    v[i].pop_front();
                    v[i].pop_front();
                }
            }
        }
        sort(v.begin(), v.end(), comp);
        if(d > 0) {
            for(int i = 0; i < m; i++) {
                int x = v[i].size();
                if(x <= 1) continue;
                if(v[i][0] == 'A') {
                    a--;
                    x--;
                    v[i].pop_front();
                }
                while(d > 0 && x > 1) {
                    d--;
                    x -= 2;
                    v[i].pop_front();
                    v[i].pop_front();
                }
            }
        }
        for(int i = 0; i < m; i++) {
            int x = v[i].size();
            for(int j = 0; j < x; j++) {
                if(v[i][j] == 'A') a--;
                else b--;
            }
        }
        if(a == 0 && b == 0 && c == 0 && d == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}