#include <stdio.h>
int k3[20];
int d[1000][1000];
void connect(int x1, int x2, int x3) {
    int i, j;
    for(i = x1; i < x2; i++) {
        for(j = x2; j < x3; j++) {
            d[i][j] = d[j][i] = 1;
        }
    }
    return;
}
int main() {
    int k, di=0, i, j;
    scanf("%d", &k);
    while(k != 0) {
        k3[di] = k%3;
        k /= 3;
        di++;
    }
    int c = 3, prv=3;
    for(i = di-1; i >= 0; i--) {
        if(k3[i] == 0) continue;
        if(i != 0) {
            d[1][c] = d[c][1] = d[c+1][1] = d[1][c+1] = d[c+2][1] = d[1][c+2] = 1;
            prv=3;
        }
        else if(k3[0] == 2) {
            d[1][c] = d[c][1] = d[1][c+1] = d[c+1][1] = 1;
            prv=2;
        }
        else {
            d[1][c] = d[c][1] = 1;
            prv=1;
        }
        for(j = 1; j < i; j++) {
            connect(c, c+3, c+6);
            c+=3;
            prv=3;
        }
        if(i != 0) {
            connect(c, c+3, c+3+k3[i]);
            c+=3;
            prv=k3[i];
        }
        for(j = 1; j < di-i; j++) {
            connect(c, c+prv, c+prv+1);
            c+=prv;
            prv = 1;
        }
        c+=prv;
        if(i != di-1 || k3[di-1] != 2) {
            d[2][c-1] = d[c-1][2] = 1;
        }
        else {
            d[2][c-1] = d[c-1][2] = d[2][c-2] = d[c-2][2] = 1;
        }
    }
    c--;
    printf("%d\n", c);
    for(i = 1; i <= c; i++) {
        for(j = 1; j <= c; j++) {
            if(d[i][j] == 0) printf("N");
            else printf("Y");
        }
        printf("\n");
    }
    return 0;
}