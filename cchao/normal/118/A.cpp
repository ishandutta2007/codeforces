#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdio>
using namespace std;
char vo[] = "aeiouyAEIOUY";
int vowel(char c)
{
        if(strchr(vo,c)) return 1;
        else return 0;
}
int main()
{
        string s;
        cin >> s;
        for(int k=0;s[k];k++)
                if(!vowel(s[k])){putchar('.');putchar(tolower(s[k]));}
        return 0;
}