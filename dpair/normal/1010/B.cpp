#include <bits/stdc++.h>
using namespace std;
int m, n;
int a[31];
int main(){
    scanf("%d%d", &m, &n);
    for (register int i = 1;i <= n;i ++){
        printf("1\n");
        fflush(stdout);
        scanf("%d", &a[i]);
        if(a[i] == 0) return 0;
    }
    int l = 1, r = m, t = 0;
    while(l <= r){
        int mid = (l + r) >> 1;
        printf("%d\n", mid);
        fflush(stdout);
        int x;scanf("%d", &x);
        t ++;
        if(t > n) t -= n;
        x *= a[t];
        if(!x) return 0;
        if(x > 0) l = mid + 1;
        else r = mid - 1;
    }
}