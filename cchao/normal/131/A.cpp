#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;
int main()
{
    char s[200];
    cin >> s;
    int up = 1;
    for(int k = 1; s[k] ; k++)
    {
        if(s[k] >= 'a' && s[k] <= 'z')
        {
            up = 0;
            break;
        }
    }
    if(up == 0) cout << s << endl;
    else
    {
        if(isupper(s[0]))
        {
            for(int k = 0; s[k]; k++)
                putchar(tolower(s[k]));
            putchar('\n');
        }
        else
        {
            putchar(toupper(s[0]));
            for(int k = 1; s[k]; k++)
                putchar(tolower(s[k]));
            putchar('\n');
        }
    }

    return 0;
}