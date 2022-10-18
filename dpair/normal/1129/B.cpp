#include <bits/stdc++.h>
using namespace std;

int k;

int main(){
    scanf("%d", &k);
    int num = k % 2000;
    int x = 1000000 - num;
    printf("2000\n");
    for (register int i = 1;i <= 1998;i ++) printf("0 ");
    printf("%d %d\n", -(x - ((x + k) / 2000)), x);
}