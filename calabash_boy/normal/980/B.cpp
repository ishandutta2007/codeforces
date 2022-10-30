#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e2+10;
int n, k;
char a[maxn][maxn];
void do0(){
    for(int i = 1; i <= k / 2; i++) {
        a[1][i] = '#';
        a[2][i] = '#';
    }
}
void do1(){
    a[1][n/2] = '#';
    k--;
    int i1 = n / 2 - 1;
    int i2 = n / 2 + 1;
    while(i1 > 0 && k > 0) {
        a[1][i1] = '#';
        a[1][i2] = '#';
        i1--;
        i2++;
        k -= 2;
    }
    i1 = 1;
    i2 = n - 2;
    while(k > 0) {
        a[2][i1] = '#';
        a[2][i2] = '#';
        i1++;
        i2--;
        k -= 2;
    }
}
int main() {
    scanf("%d%d", &n, &k);
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < n; j++) {
            a[i][j] = '.';
        }
    }
    if(k % 2 == 0) {
        do0();
    } else {
        do1();
    }
    printf("YES\n");
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < n; j++) {
            printf("%c", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}