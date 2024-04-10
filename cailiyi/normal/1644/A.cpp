#include<bits/stdc++.h>
using namespace std;
int T,num[3];
char s[10];
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",s);
        memset(num,0,sizeof num);
        int i=0;
        for(i=0;i<6;++i)
        {
            if(s[i]=='r') ++num[0];
            if(s[i]=='g') ++num[1];
            if(s[i]=='b') ++num[2];
            if(s[i]=='R' && !num[0]) break;
            if(s[i]=='G' && !num[1]) break;
            if(s[i]=='B' && !num[2]) break;
        }
        puts(i==6?"YES":"NO");
    }
    return 0;
}