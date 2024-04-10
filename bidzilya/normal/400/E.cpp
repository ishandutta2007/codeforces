#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>
 
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
#include <set>

using namespace std;
 
typedef long long ll;

int bit(int mask, int i) {
    return (mask >> i) & 1;
}

const int max_b = 20;
const int max_n = 1e5 + 100;

int n, m;
ll sum;
int a[max_n];
set<int> nulls[max_b];

pair<int, int> get_left_right_nulls(const set<int>& nulls, const int& pos) {
    set<int>::iterator itr_r = nulls.lower_bound(pos);
    set<int>::iterator itr_l = --nulls.upper_bound(pos);
    int d_r = (*itr_r);
    int d_l = (*itr_l);
    return make_pair(d_l, d_r);
}

void query(int pos, int data) {
    for (int b = 0; b < max_b; ++b)
        if (bit(data, b) == 1 && bit(a[pos], b) == 0) {
            nulls[b].erase(pos);
            pair<int, int> nl = get_left_right_nulls(nulls[b], pos);
            sum += 1LL * (1 << b) * (pos - nl.first) * (nl.second - pos);
        } else if (bit(data, b) == 0 && bit(a[pos], b) == 1) {
            pair<int, int> nl = get_left_right_nulls(nulls[b], pos);
            sum -= 1LL * (1 << b) * (pos - nl.first) * (nl.second - pos);
            nulls[b].insert(pos);
        }
    a[pos] = data;
}

int main() {
    ios_base::sync_with_stdio(false);
    
  //  freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);

    while (cin >> n >> m) {
        for (int i = 0; i <= n + 1; ++i)
            a[i] = 0;
        for (int b = 0; b < max_b; ++b) {
            nulls[b].clear();
            for (int i = 0; i <= n + 1; ++i) { 
                nulls[b].insert(i);
            }
        }
        sum = 0;
        for (int i = 1; i <= n; ++i) {
            int v;
            cin >> v;
            query(i, v);
        }
        for (int i = 1; i <= m; ++i) {
            int p, v;
            cin >> p >> v;
            query(p, v);
            cout << sum << endl;
        }
    }

    return 0;
}