#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
    int A, B, C, D;
    scanf("%d %d %d %d", &A, &B, &C, &D);
    int E = max(3*A/10, A-A*C/250);
    int F = max(3*B/10, B-B*D/250);
    
    if(E > F) printf("Misha");
    if(E < F) printf("Vasya");
    if(E == F) printf("Tie");
    return 0;
}