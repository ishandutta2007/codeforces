#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#define INF 100000000
using namespace std;
typedef long long LL;
char s[100005];
bool check(char a)
{
    if(a=='B'||a=='C'||a=='D'||a=='E'||a=='F'||a=='G'||a=='J'||a=='K'||a=='L') return 0;
    if(a=='N'||a=='P'||a=='Q'||a=='R'||a=='S'||a=='Z') return 0;
    return 1;
}
int main()
{
    int i,n,flag=1;;
    scanf("%s",s);
    n=strlen(s);
    for(i=0;i<n/2;i++)
    {
        if(s[i]!=s[n-i-1])
        {
            flag=0; break;
        }
    }
    for(i=0;i<n;i++)
    {
        if(!check(s[i]))
        {
            flag=0; break;
        }
    }
    if(flag) printf("YES\n");
    else printf("NO\n");
    return 0;
}
// davidlee1999WTK 2014/
// srO myk Orz
//ios::sync_with_stdio(false);