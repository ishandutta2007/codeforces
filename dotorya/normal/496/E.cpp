#include <stdio.h>
#include <set>
#include <algorithm>
using namespace std;
struct data1 {
    int a, b, chk;
    bool operator < (const data1 & l) const {
        return a < l.a;
    }
} d1[100050];
struct data2 { 
    int c, d, k, chk;
    bool operator < (const data2 & l) const {
        return c < l.c;
    }
} d2[100050];
struct data3 {
    data3() {
        data3(0,0,0);
    }
    data3(int a, int b, int c) {
        d = a, k = b, chk = c;
    }
    int d, k, chk;
    bool operator < (const data3 & l) const {
        return d < l.d;
    }
    bool operator == (const data3 & l) const {
        return d == l.d;
    }
    bool operator <= (const data3 & l) const {
        return d <= l.d;
    }
} tmp;
multiset <data3> bst;
int ans[100050];
int main() {
    int N, M, i, c = 1, t1, t2;
    scanf("%d", &N);
    for(i = 1; i <= N; i++) {
        scanf("%d %d", &d1[i].a, &d1[i].b);
        d1[i].chk = i;
    }
    scanf("%d", &M);
    for(i = 1; i <= M; i++) {
        scanf("%d %d %d", &d2[i].c, &d2[i].d, &d2[i].k);
        d2[i].chk = i;
    }
    sort(d1+1, d1+N+1);
    sort(d2+1, d2+M+1);
    for(i = 1; i <= N; i++) {
        while(c <= M) {
            if(d1[i].a < d2[c].c) break;
            bst.insert(data3(d2[c].d, d2[c].k, d2[c].chk));
            c++;
        }
        multiset<data3>::iterator it = bst.lower_bound(data3(d1[i].b, 0, 0));
        if(it == bst.end()) break;
        tmp = *it;
        tmp.k--;
        bst.erase(it);
        ans[d1[i].chk] = tmp.chk;
        if(tmp.k != 0) bst.insert(tmp);
    }
    if(i != N+1) printf("NO");
    else {
        printf("YES\n");
        for(i = 1; i <= N; i++) printf("%d ", ans[i]);
    }
    return 0;
}