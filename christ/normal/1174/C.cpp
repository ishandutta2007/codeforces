#include <bits/stdc++.h>
using namespace std;
int a[100001];
int main() {
    int n,num=0,sq;
    scanf ("%d",&n);sq = (int)sqrt(n);
    for (int x = 2; x <= n; x++) {
      if (!a[x]) {
        a[x] = ++num;
        if (x <= sq) for (int y = x*x;y <= n; y += x) a[y] = num;
      }
    }
    for (int x = 2; x <= n; x++) printf ("%d%c",a[x],x==n?'\n':' ');
    return 0;
}