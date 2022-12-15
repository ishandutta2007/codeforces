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
#include <bitset>
#include <vector>
using namespace std;
char s[100],c[100];
int main()
{
    int T;
    cin>>T;
    while(T--) {
        int n,cnt=0;
        scanf("%d",&n);
        scanf("%s",s);
        for(int i=0;i<=strlen(s)-7;i++)
            if(s[i]=='a'&&s[i+1]=='b'&&s[i+2]=='a'&&s[i+3]=='c'&&s[i+4]=='a'&&s[i+5]=='b'&&s[i+6]=='a')
                cnt++;
        if(cnt>=2)
        {
            printf("No\n");
            continue;
        }
        if(cnt==1)
        {
            printf("Yes\n");
            for(int i=0;i<strlen(s);i++)
            {
                if(s[i]=='?') printf("z");
                else printf("%c",s[i]);
            }
            printf("\n");
            continue;
        }
        cnt=0;
        int p;
        for(int i=strlen(s)-7;i>=0;i--)
            if((s[i]=='a'||s[i]=='?')&&(s[i+1]=='b'||s[i+1]=='?')&&(s[i+2]=='a'||s[i+2]=='?')&&(s[i+3]=='c'||s[i+3]=='?')&&(s[i+4]=='a'||s[i+4]=='?')&&(s[i+5]=='b'||s[i+5]=='?')&&(s[i+6]=='a'||s[i+6]=='?'))
            {
                for(int j=0;j<i;j++) c[j]=s[j];
                c[i]='a';c[i+1]='b';c[i+2]='a';c[i+3]='c';c[i+4]='a';c[i+5]='b';c[i+6]='a';
                for(int j=i+7;j<strlen(s);j++) c[j]=s[j];
                int f=0;
                for(int j=0;j<=strlen(s)-7;j++)
                    if(c[j]=='a'&&c[j+1]=='b'&&c[j+2]=='a'&&c[j+3]=='c'&&c[j+4]=='a'&&c[j+5]=='b'&&c[j+6]=='a')
                        f++;
                if(f==1) {
                    p = i;
                    cnt = 1;
                    break;
                }
            }
        if(cnt==0) printf("No\n");
        else
        {
            printf("Yes\n");
            for(int i=0;i<p;i++)
            {
                if(s[i]=='?') printf("z");
                else printf("%c",s[i]);
            }
            printf("abacaba");
            for(int i=p+7;i<strlen(s);i++)
            {
                if(s[i]=='?') printf("z");
                else printf("%c",s[i]);
            }
            printf("\n");
        }
    }
}