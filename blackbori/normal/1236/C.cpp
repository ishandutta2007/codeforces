#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, i, j;
    
    scanf("%d", &n);
    
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(j & 1) printf("%d ", j * n + i + 1);
            else printf("%d ", j * n + n - i);
        }
        printf("\n");
    }
    
    return 0;
}