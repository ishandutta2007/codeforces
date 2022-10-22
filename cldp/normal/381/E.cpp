#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1000010;
const int MAXM = 3000010;
const int INF = 1000000000;

int x[1000010], nn;
int l[MAXM], r[MAXM];
vector<int> s[MAXM];

int make(int a, int b) {
    int k;
    k = ++nn;
    if (a < b) {
        l[k] = nn + 1;
        make(a, (a + b) >> 1);
        r[k] = nn + 1;
        make(((a + b) >> 1) + 1, b);
        s[k] = vector<int>(s[l[k]].size() + s[r[k]].size());
        merge(s[l[k]].begin(), s[l[k]].end(), s[r[k]].begin(), s[r[k]].end(), s[k].begin());
    } else {
        s[k].push_back(x[a - 1] + 1);
    }
    return 0;
}


int find(int a, int b, int c, int d, int t) {
    if (a <= c && d <= b) {
        if (s[t].empty()) return 0;
        int l = 0, r = 0;
        l = lower_bound(s[t].begin(), s[t].end(), a) - s[t].begin();
        r = upper_bound(s[t].begin(), s[t].end(), b) - s[t].begin();
        return r - l;
    }
    int mid = (c + d) >> 1;
    int ans1 = 0, ans2 = 0;
    if (a <= mid) ans1 = find(a, b, c, mid, l[t]);
    if (mid + 1 <= b) ans2 = find(a, b, mid+1, d, r[t]);
    return ans1 + ans2;
}


int main() {
    string p;
    cin >> p;
    int n = p.size();
    vector<int> pp;
    for (int i = 0; i < n; ++i) {
        x[i] = INF;
        if (p[i] == '(') {
            pp.push_back(i);
        } else {
            if (pp.empty()) continue;
            x[pp[pp.size() - 1]] = i;
            pp.erase(pp.end() - 1);
        }
    }
    //for (int i = 0; i < n; ++i) cout << x[i] << endl;
    make(1, n);
    /*
    for (int i = 1; i <= nn; ++i) {
        cout << i << " " << l[i] << " " << r[i] << endl;
        for (int j = 0; j < s[i].size(); ++j) cout << s[i][j] << " "; cout << endl;
    }
    */
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        cout << find(a, b, 1, n, 1) * 2 << endl;
    }

    return 0;
}