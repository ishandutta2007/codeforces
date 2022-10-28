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
#define N 1000005
#define P 1000000007
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

char s[10][10]={
"1869",
"1968",
"1689",
"6198",
"1698",
"1986",
"1896"};

bool vis[10];
int num[4]={1,6,8,9},n;
char a[N],x[N];

int main()
{
    int i,j,m=0,now=0,tmp,cnt=0;
    scanf("%s",a+1);
    n=strlen(a+1);
    for(i=1;i<=n;i++)
    {
        if(a[i]=='0')
        {
            cnt++;
            continue;
        }
        x[++m]=a[i];
        tmp=now;
        now=(now*10+a[i]-48)%7;
        for(j=0;j<4;j++)
            if(num[j]==a[i]-48&&!vis[j])
            {
                vis[j]=1;
                m--;
                now=tmp;
            }
    }
    now=now*10000%7;
    x[m+1]='\0';
    printf("%s",x+1);
    printf("%s",s[(7-now)%7]);
    for(i=1;i<=cnt;i++)
        printf("0");
    cout<<endl;
    return 0;
}
// davidlee1999WTK 2016/
// srO myk Orz
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
/*
1869=0
1968=1
1689=2
6198=3
1698=4
1986=5
1896=6
*/