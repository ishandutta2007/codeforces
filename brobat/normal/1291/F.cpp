#include <bits/stdc++.h>
using namespace std;

bool ask(int x) {
    cout << '?' << ' ' << x + 1 << endl;
    char c; cin >> c;
    return c == 'Y' ? true : false;
}

void reset() {
    cout << 'R' << endl;
}

void tell(int x) {
    cout << '!' << ' ' << x << endl;
}

void solve_small(int n, int k) {
    set <int> ans;
    for(int i = 0; i < n; i++) ans.insert(i);
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            reset();
            ask(i);
            if(ask(j)) ans.erase(j);
        }
    }
    tell(ans.size());
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n, k;
    cin >> n >> k;
    if(k == 1) {
        solve_small(n, k);
        return 0;
    }
    vector<vector<int>> v;
    for(int i = 0; i < n/k; i++) {
        reset();
        vector <int> unique;
        for(int j = 0; j < k; j++) {
            auto t = ask(i*k + j);
            if(!t) unique.push_back(i*k + j);
        }
        while((int)unique.size() < k) unique.push_back(unique.front());
        v.push_back(unique);
    }
    for(int sz = k; sz < n; sz *= 2) {
        vector<vector<int>> w;
        for(int i = 0; i < (int)v.size(); i += 2) {
            // merge v[i] and v[i + 1]!
            auto a = v[i];
            auto b = v[i + 1];
            map <int, bool> rema, remb;
            for(int j = 0; j < sz; j += k) {
                // starting block of a.
                for(int t = 0; t < sz; t += k) {
                    // starting block of b. Remove duplicates in (5K/2) queries.
                    reset();
                    for(int x = 0; x < k/2; x++) {
                        ask(a[j + x]);
                    }
                    for(int x = 0; x < k/2; x++) {
                        if(ask(b[t + x])) remb[t + x] = true;
                    }
                    for(int x = 0; x < k/2; x++) {
                        if(ask(a[j + k/2 + x])) rema[j + k/2 + x] = true;
                    }
                    for(int x = 0; x < k/2; x++) {
                        if(ask(b[t + k/2 + x])) remb[t + k/2 + x] = true;
                    }
                    reset();
                    for(int x = 0; x < k/2; x++) {
                        ask(a[j + x]);
                    }
                    for(int x = 0; x < k/2; x++) {
                        if(ask(b[t + k/2 + x])) remb[t + k/2 + x] = true;
                    }
                }
            }
            vector <int> temp;
            for(int i = 0; i < sz; i++) {
                if(!rema[i]) temp.push_back(a[i]);
            }
            for(int i = 0; i < sz; i++) {
                if(!remb[i]) temp.push_back(b[i]);
            }
            while((int)temp.size() < 2*sz) temp.push_back(temp.front());
            w.push_back(temp);
        }
        v = w;
    } 
    set <int> s;
    for(auto i : v.front()) s.insert(i);
    tell((int)s.size());

    return 0;
}