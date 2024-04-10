#include <bits/stdc++.h>
#define ll long long

using namespace std;

bool check(vector<int> a) {
    for (int i = 0; i < a.size(); ++i) {
        if (abs(a[i]) >= 2) {
            return 0;
        }
    }
    return 1;
}

vector<int> mult1(vector<int> a, vector<int> b) {
    vector<int> res = {0};
    for (int i = 0; i < a.size(); ++i) {
        res.push_back(a[i]);
    }
    for (int i = 0; i < b.size(); ++i) {
        res[i] += b[i];
    }
    return res;
}

vector<int> mult2(vector<int> a, vector<int> b) {
    vector<int> res = {0};
    for (int i = 0; i < a.size(); ++i) {
        res.push_back(-a[i]);
    }
    for (int i = 0; i < b.size(); ++i) {
        res[i] += b[i];
    }
    return res;
}

struct str {
    int good;
    vector<int> a, b;
};

str solve(int depth, vector<int> a, vector<int> b) {
    if (depth == 0) {
        return {1, a, b};
    }
    vector<int> c1 = mult1(a, b);
    vector<int> c2 = mult2(a, b);
    if (check(c1)) {
        str res = solve(depth - 1, c1, a);
        if (res.good == 1)
            return res;
    }
    if (check(c2)) {
        str res = solve(depth - 1, c2, a);
        if (res.good == 1)
            return res;
    }
    return {0, {}, {}};
}

vector<int> make(vector<int> a) {
    if (a[a.size() - 1] == -1) {
        for (int i = 0; i < a.size(); ++i) {
            a[i] = -a[i];
        }
    }
    return a;
}

int main()
{
    int n;
    cin >> n;
    str ans = solve(n, {1}, {0});
    if (ans.good == 0) {
        cout << -1 << endl;
    }
    else {
        vector<int> a = ans.a;
        vector<int> b = ans.b;
        a = make(a);
        b = make(b);
        cout << a.size() - 1 << endl;
        for (auto x : a) {
            cout << x << " ";
        }
        cout << endl;
        cout << b.size() - 1 << endl;
        for (auto x : b) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}