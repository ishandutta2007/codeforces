#include <stdio.h>

int N;

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    
    scanf("%d", &N);
    int ans = 0;
    
    for(int i = 0; i < N; i++)
    {
        int x;
        scanf("%d", &x);
        if(b < x && x < c)  ans++;
    }
    printf("%d", ans);
    return 0;
}