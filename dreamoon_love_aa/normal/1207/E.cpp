#include<bits/stdc++.h>
using namespace std;
int main()
{
    printf("?");
    for(int i = 1; i <= 100; i++) printf(" %d",i);
    printf("\n");
    fflush(stdout);
    int an = 0, v;
    scanf("%d", &v);
    an = v & (127 << 7);
    
    printf("?");
    for(int i = 1; i <= 100; i++) printf(" %d",i << 7);
    printf("\n");
    fflush(stdout);
    scanf("%d", &v);
    an |= v & 127;
    printf("! %d\n", an);
    fflush(stdout);
    return 0;
}