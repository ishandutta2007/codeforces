#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

vector<int> pa, sa, pb, sb, p, s;

void fact(vector<int>& p, vector<int>& s, int n) {
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0) {
            p.push_back(i);
            s.push_back(0);
            while (n % i == 0) {
                ++s[s.size() - 1];
                n /= i;
            }
        }
    if (n > 1) {
        p.push_back(n);
        s.push_back(1);
    }
}

int main() {
    int a, b;
    cin >> a >> b;
    fact(pa, sa, a);
    fact(pb, sb, b);
    for (int i1 = 0, i2 = 0; i1 < pa.size() || i2 < pb.size(); )
        if (i1 < pa.size() && i2 < pb.size()) {
            if (pa[i1] == pb[i2]) {
                p.push_back(pa[i1]);
                s.push_back(abs(sa[i1] - sb[i2]));
                ++i1; ++i2;
            } else if (pa[i1] < pb[i2]) {
                p.push_back(pa[i1]);
                s.push_back(sa[i1]);
                ++i1;
            } else {
                p.push_back(pb[i2]);
                s.push_back(sb[i2]);
                ++i2;
            }
        } else if (i1 < pa.size()) {
            p.push_back(pa[i1]);
            s.push_back(sa[i1]);
            ++i1;
        } else if (i2 < pb.size()) {
            p.push_back(pb[i2]);
            s.push_back(sb[i2]);
            ++i2;
        }
    int ans = 0;
    for (int i = 0; i < p.size(); ++i) 
        if (p[i] == 2 || p[i] == 3 || p[i] == 5) {
            ans += s[i];
        } else {
            if (s[i] > 0) {
                cout << -1 << endl;
                return 0;
            }
        }
    cout << ans << endl;
    return 0;
}