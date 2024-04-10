#include <stdio.h>
#include <algorithm>

char a[300005];
char b[300005];
char ans[300005];

int main()
{
    scanf("%s", a);
    scanf("%s", b);
    
    int n = 0;
    
    for(; a[n] != '\0'; n++);
    
    std::sort(a, a + n);
    std::sort(b, b + n);
    
    int left = 0, right = n - 1;
    int la = 0, ra = (n - 1) / 2, lb = n - (n / 2), rb = n - 1;
    
    int i;
    for(i = 0; i < n; i++)
    {
        if(a[la] >= b[rb])   break;
        
        if(i % 2 == 0)  ans[left++] = a[la++];
        else    ans[left++] = b[rb--];
    }
    
    for(; i < n; i++)
    {
        if(i % 2)   ans[right--] = b[lb++];
        else    ans[right--] = a[ra--];
    }
    
    for(int i = 0; i < n; i++)  printf("%c", ans[i]);
    return 0;
}