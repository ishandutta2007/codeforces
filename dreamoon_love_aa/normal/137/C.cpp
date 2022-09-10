#include <cstdio>
#include <algorithm>
#define N 100000
struct pair {
    int a, b;
    bool operator<(const pair& p) const {
        return a != p.a ? a < p.a : b < p.b;
    }
    bool contains(const pair& p) const {
        return a < p.a && p.b < b;
    }
};
pair p[N];
int main() {
    int i, n, c, j;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d%d", &p[i].a, &p[i].b);
    std::sort(p, p+n);
    c = j = 0;
    for(i = 1; i < n; i++) {
        if(p[j].contains(p[i]))
            c++;
        if(p[i].b > p[j].b)
            j = i;
    }
    printf("%d\n", c);
    return 0;
}