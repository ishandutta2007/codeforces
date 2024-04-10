#include <bits/stdc++.h>

using namespace std;

int k;

vector<int> Reduce(vector<int> V) {
    vector<pair<int, int>> stk;
    int n = V.size();

    for (int i = 0; i < n; ++i) {
        if (stk.empty() || stk.back().first != V[i]) {
            stk.emplace_back(V[i], 1);
        } else {
            stk.back().second += 1;
            if (stk.back().second == k)
                stk.pop_back();
        }
    }

    vector<int> ret;
    for (auto p : stk) {
        for (int i = 0; i < p.second; ++i)
            ret.push_back(p.first);
    }
    return ret;
}

vector<int> Reduce2(vector<int> V, int& rem1, int& rem2) {
    deque<pair<int, int>> stk;
    int n = V.size();

    for (int i = 0; i < n; ++i) {
        if (stk.empty() || stk.back().first != V[i]) {
            stk.emplace_back(V[i], 1);
        } else {
            stk.back().second += 1;
            if (stk.back().second == k)
                stk.pop_back();
        }
    }

    rem1 = 0, rem2 = 0;

    while (stk.size() >= 2) {
        if (stk.front().first != stk.back().first)
            break;

        if (stk.front().second + stk.back().second >= k) {
            int need = k;
            need -= stk.back().second;
            
            rem2 += stk.back().second;
            rem1 += need;

            stk.pop_back();
            stk.front().second -= need;
            if (stk.front().second == 0)
                stk.pop_front();
        } else break;
    }

    vector<int> ret;
    for (auto p : stk) {
        for (int i = 0; i < p.second; ++i)
            ret.push_back(p.first);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> k >> m;
    vector<int> V(n);

   
    for (int i = 0; i < n; ++i) {
        cin >> V[i];
    }
    
    int minn = *min_element(V.begin(), V.end());
    int maxx = *max_element(V.begin(), V.end());
    if (minn == maxx) {
        cout << (1LL * n * m) % k;
        return 0;
    }
    
    if (k > n) {
        cout << 1LL * n * m << endl;
        return 0;
    }
    
    if (m <= 3) {
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j)
                V.push_back(V[j]);        
        }
        V = Reduce(V);
        cout << V.size() << endl;
    } else {
        V = Reduce(V);
        int n = V.size();

        int a, b;
        vector<int> W = Reduce2(V, a, b);
        
        if (W.empty()) {
            vector<int> X;
            for (int i = 0; i < n - b; ++i)
                X.push_back(V[i]);
            for (int i = a; i < n; ++i)
                X.push_back(V[i]);
            X = Reduce(X);
            cout << X.size() << endl;
            return 0;
        }
        int minn = *min_element(W.begin(), W.end());
        int maxx = *max_element(W.begin(), W.end());

        if (minn == maxx) {
//            cerr << "FLAG" << endl;
            int rem = 1LL * W.size() * (m - 2) % k;
//            cerr << "a b: " << a << " " << b << endl;

//            for (auto x : W) cerr << x << " "; cerr << endl;
            vector<int> X;
            for (int i = 0; i < (n - b); ++i) {
                X.push_back(V[i]);
            }
            for (int i = 0; i < rem; ++i) {
                X.push_back(W[0]);
            }
            for (int i = 0; i < (n - a); ++i) {
                X.push_back(V[n - (n - a) + i]);
            }
//            for (auto x : X) cerr << x << " "; cerr << endl;
            X = Reduce(X);
            cout << X.size() << endl;
        } else {
            cout << (n - a) + (n - b) + 1LL * (m - 2) * W.size() << endl;
        }

    }

    return 0;
}