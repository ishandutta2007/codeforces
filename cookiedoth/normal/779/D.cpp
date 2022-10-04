#include <iostream>

using namespace std;

const int mx = 300000;
int t[mx], p[mx], n, m, d[mx], temp;
string s;

bool check(int k) {
    int j = 0;
    for (int i = 0; i < n; ++i) {
        if ((d[i] > k) && (p[j] == t[i])) {
            j++;
            if (j >= m) break;
        }
    }
    if (j < m) return 0;
    else return 1;
}

int binsearch(int l, int r) {
    if (l == r) return l;
    int mid = (l + r) / 2;
    if (check(mid + 1)) return binsearch(mid + 1, r);
    else return binsearch(l, mid);
}

int main()
{
    cin >> s;
    n = s.length();
    for (int i = 0; i < s.length(); ++i) {
        t[i] = s[i] - 97;
    }
    cin >> s;
    m = s.length();
    for (int i = 0; i < s.length(); ++i) {
        p[i] = s[i] - 97;
    }
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        d[temp - 1] = (i + 1);
    }
    cout << binsearch(0, n) << '\n';
    return 0;
}