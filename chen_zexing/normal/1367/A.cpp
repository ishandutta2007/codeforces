#include <stdio.h>
#include <iostream>
#include <queue>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string.h>
#include <limits.h>
#include <map>
#include <string>
using namespace std;
int main() {
    int T;
    cin>>T;
    while(T--)
    {
        char s[1005];
        scanf("%s",s);
        for(int i=0;i<strlen(s);i+=2)
            printf("%c",s[i]);
        printf("%c\n",s[strlen(s)-1]);
    }
    return 0;
}