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
#define fi first
#define se second
#define N 200005
#define P 1000000007
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int main()
{
    int n,b,t,d,i;
    LL now=0,ed=0;
    queue<int> q;
    cin>>n>>b;
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&t,&d);
        while(!q.empty()&&now<=t)
        {
            q.pop();
            if(!q.empty())
                now+=q.front();
        }
        if(q.size()<=b)
        {
            if(q.empty())
                ed=now=t+d;
            else
                ed+=d;
            q.push(d);
            printf("%I64d ",ed);
        }
        else printf("-1 ");
    }
}
// davidlee1999WTK 2016/
// srO myk Orz
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000")