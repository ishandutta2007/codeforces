#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;
char s[200];
int n,k,g,t;
int main()
{
    scanf("%d%d%s",&n,&k,s);
    for(int i=0;i<n;i++)
    {if(s[i]=='G')g=i;
    else if(s[i]=='T')t=i;}
    if(g>t)k=-k;
    for(int i=g;i>=0&&i<n;i+=k)
    {
        if(s[i]=='#')break;
        if(s[i]=='T')
        {
            printf("YES");return 0;
        }
    }
    printf("NO");
    return 0;
}