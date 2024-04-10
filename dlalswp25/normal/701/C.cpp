#include <stdio.h>

int n;
char s[100005];
bool pok[127];
int num[127];

int main()
{
    scanf("%d", &n);
    scanf("%s", s);
    
    for(int i = 0; i < n; i++)  pok[s[i]] = true;
    
    int left, right, mid;
    bool isPossible;
    
    left = 1, right = n;
    
    while(left <= right)
    {
        for(int i = 0; i < 127; i++)
        {
            if(pok[i])  num[i] = 0;
            else    num[i] = 1;
        }
        
        mid = (left + right) / 2;
        
        for(int i = 0; i < mid; i++)
        {
            num[s[i]]++;
        }
        
        for(int i = mid; i <= n; i++)
        {
            isPossible = true;
            for(int j = 0; j < 127; j++)    if(num[j] == 0) isPossible = false;
            if(isPossible)  break;
            
            if(i == n)  break;
            
            num[s[i - mid]]--;
            num[s[i]]++;
        }
        
        if(isPossible)  right = mid - 1;
        else    left = mid + 1;
    }
    
    printf("%d", left);
    return 0;
}