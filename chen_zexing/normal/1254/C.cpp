#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
vector <int> ll,lr,rl,rr;
vector <int> l,r;
double h[1005];
bool cmp(int a,int b){
    return h[a]>h[b];
}
int main() {
    int n;
    double t;
    cin >> n;
    int tt;
    int fl = 0, fr = 0, flr = 0, fll = 0, frl = 0, frr = 0;
    for (int i = 3; i <= n; i++) {
        printf("2 1 2 %d\n", i);
        fflush(stdout);
        scanf("%d", &tt);
        if (tt > 0) l.push_back(i), fl = 1;
        else r.push_back(i), fr = 1;
    }
    if (fl) {
        for (int i = 0; i < l.size(); i++) {
            printf("1 1 2 %d\n", l[i]);
            fflush(stdout);
            scanf("%lf", &t);
            h[l[i]] = t;
        }
        sort(l.begin(), l.end(), cmp);
        ll.push_back(l[0]),fll=1;
        for (int i = 1; i < l.size(); i++) {
            printf("2 1 %d %d\n", l[0], l[i]);
            fflush(stdout);
            scanf("%d", &tt);
            if (tt < 0) lr.push_back(l[i]), flr = 1;
            else ll.push_back(l[i]), fll = 1;
        }
    }
    if (fr) {
        for (int i = 0; i < r.size(); i++) {
            printf("1 1 2 %d\n", r[i]);
            fflush(stdout);
            scanf("%lf", &t);
            h[r[i]] = t;
        }
        sort(r.begin(), r.end(), cmp);
        rl.push_back(r[0]),frl=1;
        for (int i = 1; i < r.size(); i++) {
            printf("2 1 %d %d\n", r[0], r[i]);
            fflush(stdout);
            scanf("%d", &tt);
            if (tt < 0) rl.push_back(r[i]), frl = 1;
            else rr.push_back(r[i]), frr = 1;
        }
    }
    printf("0 1 ");
    if (frl) for (int i = rl.size() - 1; i >= 0; i--) printf("%d ", rl[i]);
    if (frr) for (int i = 0; i < rr.size(); i++) printf("%d ", rr[i]);
    printf("2 ");
    if (flr) for (int i = lr.size() - 1; i >= 0; i--) printf("%d ", lr[i]);
    if (fll) for (int i = 0; i < ll.size(); i++) printf("%d ", ll[i]);
    return 0;
}