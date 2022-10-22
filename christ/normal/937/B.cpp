#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int main () {
    int p,y;
    scanf ("%d %d",&p,&y);
    for (int i = y; i > p; i--) {
        for (int j = 2; j * j <= i; j++) if (i % j == 0) {
            if (j <= p || i/j <= p) {
                goto fail;
            }
        }
        printf ("%d\n",i);
        return 0;
        fail:;
    }
    printf ("-1\n");
    return 0;
}