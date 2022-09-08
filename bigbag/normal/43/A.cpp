#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 111;

int n;
string s[max_n];
set <string> q;
map <string, int> m;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        q.insert(s[i]);
        m[s[i]]++;
    }
    if (q.size() == 1) {
        cout << s[0];
    } else {
        string a, b;
        a = *q.begin();
        q.erase(a);
        b = *q.begin();
        if (m[a] > m[b]) {
            cout << a << endl;
        } else {
            cout << b << endl;
        }
    }
    return 0;
}