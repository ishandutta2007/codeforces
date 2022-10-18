#include <bits/stdc++.h>
using namespace std;

int n;
int a[65];
int main(){
    scanf("%d", &n);
    if(n <= 60){
        for (register int i = 1;i <= n;i ++){
            printf("? %d\n", i);
            fflush(stdout);
            scanf("%d", &a[i]);
        }
        sort(a + 1, a + n + 1);
        printf("! %d %d\n", a[1], a[2] - a[1]);
        fflush(stdout);
        return 0;
    }
    int l = 0, r = 1000000000;
    int tot = 60, ans = 1000000000;
    while(l <= r){
        int mid = (l + r) >> 1;
        printf("> %d\n", mid);
        tot --;
        fflush(stdout);
        int res;scanf("%d", &res);
        if(!res) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    srand(time(NULL));
    tot = 15;
    for (register int i = 1;i <= tot;i ++){
        printf("? %d\n", rand() % n + 1);
        fflush(stdout);
        scanf("%d", &a[i]);
    }
    if(a[1] == a[2] && a[2] == a[3] && a[3] == a[6] && a[6] == a[11]){
        printf("! 0 %d\n", ans);
        fflush(stdout);
        return 0;
    }
    for (register int i = 1;i <= ans / (n - 1);i ++){
        int b = ans - (i * n);
        int c = (b % i + i) % i;
        bool ck = 1;
        for (register int j = 1;j <= tot;j ++){
            if(a[j] % i != c || ((a[j] - b) / i) <= 0){
                ck = 0;
                break;
            }
        }
        if(ck){
            printf("! %d %d\n", i + b, i);
            fflush(stdout);
            return 0;
        }
    }
}