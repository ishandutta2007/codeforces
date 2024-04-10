#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    scanf ("%d",&n);
    int m = (n>>1)+1;
    printf ("%d\n",m);
    for (int x = 1; x <= m; x++, n--) printf ("%d %d\n",1,x);
    for (int x = 2; x <= m && n; x++, n--) printf ("%d %d\n",m,x);
}