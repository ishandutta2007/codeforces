#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<utility>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<queue>
#include<stack>
#include<bitset>
#include<ctime>
#include<deque>
#define N 100005
#define P 1000000007
#define INF 1000000000
#define fi first
#define se second
#define debug(x) cerr<<#x<<' '<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
int main()
{
    int n,m,i,j,flag=0;
    char s;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            cin>>s;
            if(s=='C'||s=='Y'||s=='M')
                flag=1;
        }
    }
    if(flag)
        printf("#Color\n");
    else printf("#Black&White\n");
    return 0;
}