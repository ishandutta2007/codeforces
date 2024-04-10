#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int t, x, a, b, c, i;
    
    scanf("%d", &t);
    
    for(; t--; ){
        scanf("%d%d%d", &a, &b, &c);
        for(i=0, x=0; i<=a && i+i<=b; i++){
            x = max(x, i * 3 + min(c / 2, b - i - i) * 3);
        }
        printf("%d\n", x);
    }
    
    return 0;
}