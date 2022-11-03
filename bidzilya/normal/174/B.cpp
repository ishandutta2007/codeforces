#include <cstdio>
#include <cstring>

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <map>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;

string s;

int main() {
    cin >> s;
    vector<int> l, r, p;
    for (int i = 0; i < (int) s.length(); ++i)
        if (s[i] == '.')
            p.push_back(i);
    if (p.size() == 0 || p[0] == 0 || p[0] > 8) {
        cout << "NO" << endl;
        return 0;
    }
    l.push_back(0);
    for (int i = 1; i < (int) p.size(); ++i) {
        int dl = p[i] - p[i - 1] - 1;
        if (dl > 11 || dl <= 1) {
            cout << "NO" << endl;
            return 0;
        }
        if (dl >= 4) {
            r.push_back(p[i - 1] + 3);
            l.push_back(p[i - 1] + 4);
        } else {
            r.push_back(p[i - 1] + 1);
            l.push_back(p[i - 1] + 2);
        }
    }
    int dl = s.length() - p[p.size() - 1] - 1;
    if (dl > 3 || dl == 0) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    r.push_back(s.length() - 1);
    for (int i = 0; i < (int) l.size(); ++i) {
        for (int j = l[i]; j <= r[i]; ++j)
            cout << s[j];
        cout << endl;
    }
    return 0;
}