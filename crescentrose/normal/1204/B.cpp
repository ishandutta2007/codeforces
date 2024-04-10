#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <deque>
#include <set>
#include <vector>
#include <unordered_map>
using namespace std;
int n, l, r;
int a[1001];
int main() {
    scanf("%d %d %d", &n,&l, &r);
    a[1] = 1;
    for (int i = 2; i <= r ; i ++)
        a[i] = a[i - 1] * 2;
    int v = 0;
    for (int i = 1; i <= l; i ++) {
        v += a[i];
    }
    v += n - l;
    printf("%d ", v);
    v = 0;
    for (int i = 1; i <= r; i ++)
        v += a[i];
    v += (n - r) * (a[r]);
    printf("%d", v);
    return 0;
}