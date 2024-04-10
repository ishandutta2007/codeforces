//  228

#include <bits/stdc++.h>
using namespace std;
 
int nm, nz;
vector<int> a;
 
void check(string &s) {
    int n = s.size();
    if (n >= 4 && s.substr(n - 4, 4) == "lios") {
        ++nm;
        a.push_back(1);
    }
    else if (n >= 5 && s.substr(n - 5, 5) == "liala") {
        ++nz;
        a.push_back(1);
    }
    else if (n >= 3 && s.substr(n - 3, 3) == "etr") {
        ++nm;
        a.push_back(2);
    }
    else if (n >= 4 && s.substr(n - 4, 4) == "etra") {
        ++nz;
        a.push_back(2);
    }
    else if (n >= 6 && s.substr(n - 6, 6) == "initis") {
        ++nm;
        a.push_back(3);
    }
    else if (n >= 6 && s.substr(n - 6, 6) == "inites") {
        ++nz;
        a.push_back(3);
    }
    else {
        cout << "NO\n";
        exit(0);
    }
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    getline(cin, s);
    s += ' ';
    string now;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == ' ') {
            if (!now.empty()) check(now);
            now.clear();
        }
        else now += s[i];
    }
    if (nm > 0 && nz > 0) {
        cout << "NO\n";
        return 0;
    }
    if (a.size() == 1) {
        cout << "YES\n";
        return 0;
    }
    int num2 = 0;
    for (int i = 0; i < a.size(); ++i) if (a[i] == 2) ++num2;
    if (num2 != 1) {
        cout << "NO\n";
        return 0;
    }
    for (int i = 1; i < a.size(); ++i) {
        if (a[i - 1] > a[i]) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}