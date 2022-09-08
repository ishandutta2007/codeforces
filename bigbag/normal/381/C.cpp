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

const int max_n = 111111, inf = 111111111;

struct state{
    unsigned long long l, r;
    int mod;
};

state make_state(unsigned long long l, unsigned long long r, int mod) {
    state ret;
    ret.l = l;
    ret.r = r;
    ret.mod = mod;
    return ret;
}

int n;
map <unsigned long long, int> m;
vector<state> v;

int get_ans(unsigned long long poz) {
    if (m.count(poz)) {
        return m[poz];
    }
    int l = 0, r = v.size();
    while (r - l > 1) {
        int x = (l + r) / 2;
        if (v[x].l <= poz && poz <= v[x].r) {
            l = x;
            break;
        }
        if (poz < v[x].l) {
            r = x;
        }
        else {
            l = x;
        }
    }
    //cout << "!!!  " << poz << ' ' << l << ' ' << v[l].l << ' ' << v[l].r << "  " << v[l].mod << endl;
    //for (int i = 0; i /3 < inf; ++i);
    if ((poz - v[l].l + 1) % v[l].mod == 0) {
        return get_ans(v[l].mod);
    }
    return get_ans((poz - v[l].l + 1) % v[l].mod);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    unsigned long long len = 0;
    for (int i = 0; i < n; ++i) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            int x;
            scanf("%d", &x);
            ++len;
            m[len] = x;
        } else {
            unsigned long long l, x;
            scanf("%I64d%I64d", &l, &x);
            v.push_back(make_state(len + 1, len + l * x, l));
            len += l * x;
        }
    }
    /*cout << endl;
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i].l << ' ' << v[i].r << endl;
    }
    cout << endl;*/
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        unsigned long long poz;
        scanf("%I64d", &poz);
        printf("%d ", get_ans(poz));
    }
    return 0;
}