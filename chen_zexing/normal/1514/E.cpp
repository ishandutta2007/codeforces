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
int ans[105][105];
int a[105], b[105];
int query1(int a,int b) {
    printf("1 %d %d\n", a, b);
    fflush(stdout);
    int t;
    scanf("%d", &t);
    return t;
}
int query2(int x,int pos) {
    printf("2 %d %d ", x, pos + 1);
    for (int i = 0; i <= pos; i++) printf("%d ", a[i]);
    puts("");
    fflush(stdout);
    int t;
    scanf("%d", &t);
    return t;
}
void merge(int l,int r) {
    if (l == r) return;
    int mid = (l + r) >> 1;
    merge(l, mid);
    merge(mid + 1, r);
    int p1 = l, p2 = mid + 1, x = l - 1;
    while (p1 <= mid || p2 <= r) {
        if (p1 > mid) b[++x] = a[p2++];
        else if (p2 > r) b[++x] = a[p1++];
        else {
            if (query1(a[p1], a[p2])) b[++x] = a[p1++];
            else b[++x] = a[p2++];
        }
    }
    for (int i = l; i <= r; i++) a[i] = b[i];
}
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n, t;
        cin >> n;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                ans[i][j] = 1;
        for (int i = 0; i < n; i++) a[i] = i;
        merge(0, n - 1);
        int now = n - 1, pos = n - 2;
        while (now >= 0) {
            if (now == pos) {
                for (int i = pos + 1; i < n; i++)
                    for (int j = 0; j <= pos; j++)
                        ans[a[i]][a[j]] = 0;
                pos--;
            }
            while (pos >= 0 && query2(a[now], pos)) pos--;
            now--;
        }
        printf("3\n");
        for (int i = 0; i < n; i++, puts(""))
            for (int j = 0; j < n; j++)
                printf("%d", ans[i][j]);
        fflush(stdout);
        scanf("%d", &t);
    }
    return 0;
}
//
/// 
//01
// 
//
//dp