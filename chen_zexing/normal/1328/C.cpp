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
using namespace std;
char s[50005],a[50005],b[50005];
int main() {
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,f=0;
        scanf("%d",&n);
        scanf("%s",s);
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0')
            {
                a[i]='0';
                b[i]='0';
            }
            else if(s[i]=='2'&&f==0)
            {
                a[i]='1';
                b[i]='1';
            }
            else if(s[i]=='2'&&f)
            {
                a[i]='0';
                b[i]='2';
            }
            else if(s[i]=='1'&&f==0)
            {
                a[i]='1';
                b[i]='0';
                f=1;
            }
            else if(s[i]=='1'&&f)
            {
                a[i]='0';
                b[i]='1';
            }
        }
        for(int i=0;i<n;i++) printf("%c",a[i]);
        printf("\n");
        for(int i=0;i<n;i++) printf("%c",b[i]);
        printf("\n");
    }
    return 0;
}