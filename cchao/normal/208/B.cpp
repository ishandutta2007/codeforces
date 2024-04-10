#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
using namespace std;
#define sz size()
#define mp(a,b) make_pair(a,b)
#define LOOP(_index,_times) for(int _index = 0; _index<_times;_index++)
#define FOR(_index,_start,_end) for(int _index=_start;_index<_end;_index++)
#define FORE(_index,_start,_end) for(int _index=_start;_index<=_end;_index++)
int OK(int a, int b)
{
    return (a/13 == b/13 || a%13 == b%13) ? 1 : 0;
}

int icard[52];

int to_i(char *s)
{
    int a,b;
     switch(s[0])
     {
         case '2': a=0; break;
         case '3': a=1; break;
         case '4': a=2; break;
         case '5': a=3; break;
         case '6': a=4; break;
         case '7': a=5; break;
         case '8': a=6; break;
         case '9': a=7; break;
         case 'T': a=8; break;
         case 'J': a=9; break;
         case 'Q': a=10; break;
         case 'K': a=11; break;
         case 'A': a=12; break;
     }
     switch(s[1])
     {
         case 'S': b = 0; break;
         case 'D': b = 1; break;
         case 'H': b = 2; break;
         case 'C': b = 3; break;
     }
     return a + b * 13;
}

short int dp[52][52][52][52] = {0};
int dfs(int position, int a, int b, int c)
{
    //printf("%d %d %d %d\n",position,a,b,c);
    if(position == -1)
    {
        if(OK(a,c) && OK(b,c)) return 2;
        return -1;
    }
    if (dp[position][a][b][c] != 0)
    {
        return dp[position][a][b][c];
    }
    if(OK(c,b) && dfs(position-1, icard[position], a, c)==2) return dp[position][a][b][c]=2;
    if(OK(c,icard[position]) && dfs(position-1,c,a,b)==2) return dp[position][a][b][c]=2;
    return dp[position][a][b][c]=-1;
}

int main()
{
    int n;
    scanf("%d",&n);
    char str[4];
    for(int k=0;k<n;k++)
    {
        scanf("%s",str);
        icard[k] = to_i(str);
    }
    if(n==1)
    {
        puts("YES");
    }
    else if(n==2)
    {
        if(OK(icard[0],icard[1])) puts("YES");
        else puts("NO");
    }
    else if(n==3)
    {
        if(OK(icard[0],icard[2]) && OK(icard[1],icard[2])) puts("YES");
        else puts("NO");
    }
    else
    {
        if(dfs(n-4,icard[n-3],icard[n-2],icard[n-1])==2) puts("YES");
        else puts("NO");
    }
    return 0;
}