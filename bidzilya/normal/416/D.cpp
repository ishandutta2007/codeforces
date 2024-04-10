#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>
#include <iostream>
using namespace std;

typedef long long ll;

const int max_n = 2e5 + 10;

int a[max_n];
int n;
pair<int, int> p[max_n];
  
int calc_ans(int pos) 
{
    if (p[pos].first == -1 || p[pos].second == -1) return n;
    int i1 = p[pos].first;
    int i2 = p[pos].second;
    
    int d = a[i2] - a[i1];
    
    if (d % (i2 - i1) != 0) return i2;
    
    d /= (i2 - i1);
    
    if (a[i2] - 1LL * d * (i2 - pos) <= 0) return i2;
    
    int j = i2;
    ll x = a[i2];
    while (j + 1 < n && x + d > 0 && (a[j + 1] == -1 || a[j + 1] == x + d)) {
        x += d;
        ++j;
    }
    
    return j + 1;
}
    
int main()
{
   // freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    
    p[n].first = p[n].second = -1;
    for (int i = n - 1; i >= 0; --i) {
        p[i] = p[i + 1];
        if (a[i] != -1) {
            p[i].second = p[i].first;
            p[i].first = i;
        }
    }
    
    int ans = 0;
    int pos = 0;
    while (pos < n) {
        ++ans;
        pos = calc_ans(pos);
    }
    printf("%d\n", ans);

    return 0;
}