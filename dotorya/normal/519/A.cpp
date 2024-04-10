#include <stdio.h>
char d[10];
int main() {
    int i, j, sum_a = 0, sum_b = 0;
    for(i = 1; i <= 8; i++) {
        scanf("%s", d);
        for(j = 0; j <= 7; j++) {
                if(d[j] == 'Q') sum_a += 9;
                if(d[j] == 'R') sum_a += 5;
                if(d[j] == 'B') sum_a += 3;
                if(d[j] == 'N') sum_a += 3;
                if(d[j] == 'P') sum_a += 1;
                if(d[j] == 'q') sum_b += 9;
                if(d[j] == 'r') sum_b += 5;
                if(d[j] == 'b') sum_b += 3;
                if(d[j] == 'n') sum_b += 3;
                if(d[j] == 'p') sum_b += 1;
        }
    }
    if(sum_a > sum_b) printf("White");
    else if(sum_a < sum_b) printf("Black");
    else printf("Draw");
    return 0;
}