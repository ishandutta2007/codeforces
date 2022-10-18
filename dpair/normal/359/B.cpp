#include <bits/stdc++.h>
using namespace std;

int n, k;

int main(){
    scanf("%d%d", &n, &k);
    for (register int i = 1;i <= n;i ++){
        if(i <= k) printf("%d %d ", (i << 1 | 1) - 1, (i << 1) - 1);
        else printf("%d %d ", (i << 1) - 1, (i << 1 | 1) - 1);
    }
}