#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
using namespace std;
int main()
{
    int n;
    char s[1200];
    int b[26] = {0};
    int t[26] = {0};
    scanf("%d%s",&n,s);
    for(int k = 0; s[k] ; k++)
        b[s[k]-'a']++;
    for(int k = 0; k < 26; k++)
    {
        if(b[k]%n != 0)
        {
            puts("-1");
            return 0;
        }
        t[k] = b[k]/n;
    }
    while(n--)
    {
        for(int k = 0; k < 26; k++)
        {
            for(int j = 0; j < t[k]; j++)
                putchar(k + 'a');
        }
    }
    putchar('\n');
    return 0;
}