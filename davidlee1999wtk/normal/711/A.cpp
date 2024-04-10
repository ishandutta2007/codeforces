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
char s[1005][10];
int main()
{
    int n,i,j,flag=0;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        scanf("%s",s[i]+1);
        if(!flag)
            if(s[i][1]=='O'&&s[i][2]=='O')
                s[i][1]=s[i][2]='+',flag=1;
            else if(s[i][4]=='O'&&s[i][5]=='O')
                s[i][4]=s[i][5]='+',flag=1;
    }
    if(!flag)
        printf("NO\n");
    else
    {
        printf("YES\n");
        for(i=1;i<=n;i++)
            printf("%s\n",s[i]+1);
    }
    return 0;
}
// davidlee1999WTK 2016/
// srO myk Orz
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
/*

*/