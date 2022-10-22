#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using ll = long long;
const int MN = 5e3+2;
int ans[MN][MN], qu[MN][MN];
int pxa[MN], a[MN];
int main() {
    int n;
    scanf ("%d",&n);
    for (int i = 1; i <= n; i++) {
        scanf ("%d",&a[i]);
        pxa[i] = pxa[i-1] ^ a[i];
    }
    for (int i = 1; i <= n; i++) qu[i][i] = ans[i][i] = a[i];
    for (int len = 1; len < n; len++) {
        for (int l = 1; l <= n-len; l++) {
            ans[l][l+len] = ans[l+1][l+len] ^ ans[l][l+len-1];
            qu[l][l+len] = max(qu[l][l+len-1],max(qu[l+1][l+len],ans[l][l+len]));
        }
    }
    int q,a,b;
    scanf ("%d",&q);
    while (q--) {
        scanf ("%d %d",&a,&b);
        printf ("%d\n",qu[a][b]);
    }
    return 0;
}