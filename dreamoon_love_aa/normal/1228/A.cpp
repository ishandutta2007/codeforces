#include<bits/stdc++.h>
bool valid(int x){
    int d[20], dn = 0;
    while(x){
        d[dn++] = x % 10;
        x /= 10;
    }
    std::sort(d, d + dn);
    for(int i = 1; i < dn; i++) {
        if(d[i] == d[i - 1]) return 0;
    }
    return 1;
}
int main() {
    int l,r;
    scanf("%d%d", &l, &r);
    for(int i = l; i <= r; i++) {
        if(valid(i)) {
            printf("%d\n", i);
            return 0;
        }
    }
    puts("-1");
    return 0;
}