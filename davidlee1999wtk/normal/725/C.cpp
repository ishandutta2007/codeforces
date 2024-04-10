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
#include<iomanip>
#include<deque>
#include<utility>
#define INF 1000000000
#define fi first
#define se second
#define N 100005
#define P 1000000007
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
char s[30];
char rel[3][30];
int vis[200];
int main()
{
    int n,i,f1,f2,st,j;
    scanf("%s",s+1);
    for(i=1;i<=27;i++)
        if(!vis[s[i]])
            vis[s[i]]=i;
        else
        {
            if(vis[s[i]]==i-1)
            {
                printf("Impossible\n");
                return 0;
            }
            else f1=vis[s[i]],f2=i;
        }
    //debug(f1);
    //debug(f2);
    if(f1>28-f2)
    {
        reverse(s+1,s+1+27);
        f1=28-f1,f2=28-f2;
        swap(f1,f2);
    }
    n=(f2-f1+1)/2;
    //debug(n);
    st=n+f1-1;
    //debug(st);
    for(i=st,j=1;i>=1;i--,j++)
        rel[1][i]=s[j];
    for(i=1;i<=(f2-f1)-n;i++,j++)
        rel[2][i]=s[j];
    j++;
    for(;i<=st;i++)
        rel[2][i]=s[j++];
    for(;i<=13;i++)
    {
        rel[1][i]=s[j++];
        rel[2][i]=s[j++];
    }
    printf("%s\n",rel[1]+1);
    printf("%s",rel[2]+1);
    return 0;
}
// davidlee1999WTK 2016/
// srO myk Orz
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
/*
XTSHBGLRJAMDUIPCWYOZVERNKQF
*/