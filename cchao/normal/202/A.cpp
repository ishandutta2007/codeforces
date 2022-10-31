#include <cstdio>
#include <cstring>
int main()
{
    char s[100];
    scanf("%s",s);
    int cnt = 0;
    char max = 0;
    for(int k =0 ;s[k] ; k++)
    {
        if(s[k] > max)
        {
            max = s[k];
            cnt = 1;
        }
        else if(s[k] == max)
        {
            cnt++;
        }
    }
    for(int k =0 ; k < cnt; k++)
        putchar(max);
    return 0;
}