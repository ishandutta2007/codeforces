#include <stdio.h>
#include <algorithm>
struct data {
    int x, y; // x : , y : 
    bool operator < (const data & l) const {
        if(x == 0) return false;
        else if(l.x == 0) return true;
        else return (y*l.x < x*l.y);
    }
    bool operator != (const data & l) const {
        if(x == 0 && l.x == 0) return false;
        else if(x == 0 || l.x == 0) return true;
        else if(y*l.x != x*l.y) return true;
        else return false;
    }
} d[1050];
int gcd(int a, int b) {
    if(a>b) std::swap(a,b);
    if(b%a==0) return a;
    else return gcd(b%a, a);
}
int main() {
    int N, x0, y0, i, t1, t2, chk, g;
    scanf("%d %d %d", &N, &x0, &y0);
    for(i = 1; i <= N; i++) {
        scanf("%d %d", &t1, &t2);
        t1 -= x0, t2 -= y0;
        if(t1 == 0) {
            d[i].x = 0, d[i].y = 1;
            continue;
        }
        if(t2 == 0) {
            d[i].x = 1, d[i].y = 0;
            continue;
        }
        chk = 0;
        if(t1 < 0) {
            chk++;
            t1 *= -1;
        }
        if(t2 < 0) {
            chk++;
            t2 *= -1;
        }
        g = gcd(t1, t2);
        t1 = t1/g;
        t2 = t2/g;
        if(chk == 1) t2 *= -1;
        d[i].x = t1, d[i].y = t2;
    }
    std::sort(d+1, d+N+1);
    int cnt = 0, st;
    for(i = 1; i <= N; i++) {
        cnt++, st = i;
        while(i < N) {
            if(d[st] != d[i+1]) break;
            i++;
        }
    }
    printf("%d", cnt);
    return 0;
}