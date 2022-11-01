#include <bits/stdc++.h>

int main()
{
    int T;
    scanf("%d", &T); 
    while (T--)
    {
        const int MaxN = 2e5 + 5; 
        int n; 
        static int a[MaxN]; 
        
        scanf("%d", &n); 
        
        bool flg = false; 
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", a + i); 
            if (i > 1 && abs(a[i] - a[i - 1]) > 1 && !flg)
            {
                flg = true; 
                puts("YES");
                printf("%d %d\n", i - 1, i); 
            }
        }
        if (!flg)
            puts("NO"); 
    }
    return 0; 
}