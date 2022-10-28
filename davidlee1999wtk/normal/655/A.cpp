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
#include<string>
#include<bitset>
#define INF 1000000000
#define N 100005
#define P 1000000007
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
char s1[3][3],s2[3][3],s[10],t[10];
int main()
{
    scanf("%s",s1[1]+1);
    scanf("%s",s1[2]+1);
    scanf("%s",s2[1]+1);
    scanf("%s",s2[2]+1);
    int i,j,k;
    s[1]=s1[1][1];
    s[2]=s1[1][2];
    s[3]=s1[2][2];
    s[4]=s1[2][1];
    for(i=1;i<=4;i++)
        if(s[i]=='X')
        {
            for(j=i+1;j<=4;j++)
                s[j-1]=s[j];
            break;
        }
    t[1]=s2[1][1];
    t[2]=s2[1][2];
    t[3]=s2[2][2];
    t[4]=s2[2][1];
    for(i=1;i<=4;i++)
        if(t[i]=='X')
        {
            for(j=i+1;j<=4;j++)
                t[j-1]=t[j];
            break;
        }
    int flag=0;
    for(i=1;i<=3;i++)
    {
        //debug(s[i]);
        s[i+3]=s[i];
    }
    for(k=1;k<=3;k++)
    {
        for(i=1;i<=3;i++)
            if(s[i+k]!=t[i])
                break;
        if(i==4)
            flag=1;
    }
    if(flag) printf("YES\n");
    else printf("NO\n");
    return 0;
}
// davidlee1999WTK 2016/
// srO myk Orz
//ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000")
//#define O2 __attribute__((optimize("-O2")))