#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,m;
    scanf ("%d %d",&n,&m);
    if (m) printf ("%d\n",min(m,n-m));
    else printf ("1\n");
    return 0;
}