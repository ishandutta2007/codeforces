#include <bits/stdc++.h>
using namespace std;

int n, k;

int main(){
    scanf("%d%d", &n, &k);
    printf("%d\n", (n * 6 - 1) * k);
    for (register int i = 1;i <= n;i ++){
        printf("%d %d %d %d\n", (i * 6 - 5) * k, (i * 6 - 4) * k, (i * 6 - 3) * k, (i * 6 - 1) * k);
    }
}