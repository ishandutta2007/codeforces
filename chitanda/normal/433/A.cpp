#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;
#define ll long long

int n, x, t1, t2, tot;

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &x); x /= 100;
        tot += x;
        if (x==1) t1++;
        else if (x==2) t2++;
    }
    if (tot & 1) { printf("NO\n"); return 0; }
    t2 %= 2;
    if (t2 & !t1) { printf("NO\n"); return 0; }
    printf("YES\n");
    return 0;
}