#include <bits/stdc++.h>
using namespace std;

int a[100000 + 10];
int n, l, x, y;
set<int> all;
vector<int> f(int x) {
    vector<int> ret, emp;
    int idx = lower_bound(a, a + n, x) - a;
    if(a[idx] == x) return ret;

    for(int i = 0; i < n && a[i] + x <= l; ++i) {
        ret.push_back(a[i] + x);
        if(all.count(ret.back())) return emp;
    }

    while(idx < n) {
        ret.push_back(a[idx++] - x);
        if(all.count(ret.back())) return emp;
    }
    return ret;
}
set<int> s;
int main() {
    scanf("%d%d%d%d", &n, &l, &x, &y);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        all.insert(a[i]);
    }
    vector<int> xx = f(x);
    vector<int> yy = f(y);
    if(xx.size() == 0 && yy.size() == 0) {
        puts("0");
    }
    else if(xx.size() == 0) {
        puts("1");
        printf("%d\n", yy[0]);
    }
    else if(yy.size() == 0) {
        puts("1");
        printf("%d\n", xx[0]);
    }
    else {
        for(auto v: xx) s.insert(v);
        for(auto v: yy) if(s.count(v)) {
            puts("1");
            printf("%d\n", v);
            return 0;
        }
        puts("2");
        printf("%d %d\n", xx[0], yy[0]);
    }

    return 0;
}