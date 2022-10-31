#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#define N 3000
#define M 110000
#define LL long long
#define inf 1000000001
using namespace std;
map< long long, int > dic;
set< long long > illegal;
char s[71000][20];
int main()
{
    //freopen("1.in","r",stdin);
    int n;
    scanf("%d",&n);
    dic.clear();
    illegal.clear();
    long long now,tmp;
    int len;
    for(int ti=1;ti<=n;ti++)
    {
        scanf("%s",s[ti]);
        for(int i=0;i<9;i++)
        {
            now=0;
            for(int j=i;j<9;j++)
            {
                now=now*10+s[ti][j]-'0';
                len=j-i+1;
                tmp=now*10+len;
                if (dic.find(tmp)!=dic.end())
                {
                    if (dic[tmp]!=ti)illegal.insert(tmp);
                }
                dic[tmp]=ti;
            }
        }
    }
    for(int ti=1;ti<=n;ti++)
    {
        int ansp,ans;
        ans=2147483647;
        for(int i=0;i<9;i++)
        {
            now=0;
            for(int j=i;j<9;j++)
            {
                now=now*10+s[ti][j]-'0';
                len=j-i+1;
                tmp=now*10+len;
                if (len>=ans)continue;
                if (illegal.find(tmp)!=illegal.end())continue;
                ans=len; ansp=i;
            }
        }
        for(int i=ansp;i<=ansp+ans-1;i++)putchar(s[ti][i]);
        puts("");
    }
}