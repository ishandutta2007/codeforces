#include <stdio.h>
#include <algorithm>
using namespace std;

double d[105];
int main() {
    double A = 0, B = 1;
    int N, i, j;
    scanf("%d",&N);
    for(i = 1; i <= N; i++) scanf("%lf", &d[i]);
    sort(d+1, d+N+1);

    double ANS = 0;
    for(i = 1; i <= N; i++) {
        A = 0, B = 1;
        for(j = i; j <= N; j++) {
            if(A>B) break;
            A = B*d[j]+A*(1-d[j]);
            B = B*(1-d[j]);
        }
        if(ANS < A) ANS = A;
    }
    printf("%.20lf", ANS);
    return 0;
}