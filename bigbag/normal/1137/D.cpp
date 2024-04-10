#include <bits/stdc++.h>

using namespace std;

const int max_n = 5055, inf = 1000111222;

string s;
vector<vector<string>> v;

vector<string> step(const string &s) {
    cout << "next ";
    for (char c : s) {
        cout << c << " ";
    }
    cout << endl;
    int k;
    cin >> k;
    vector<string> res(k);
    for (int i = 0; i < k; ++i) {
        cin >> res[i];
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    vector<string> v;
    while (v.size() != 2) {
        v = step("01");
        v = step("1");
    }
    while (v.size() != 1) {
        v = step("0123456789");
    }
    cout << "done" << endl;
    return 0;
}