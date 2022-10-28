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
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int pri[1000005];
bool vis[10000005]={0};
void getprime()
{
    LL i,j,cou=0;
    for(i=2;i<=10000000;i++)
        if(!vis[i])
        {
            pri[++cou]=i;
            for(j=i*i;j<=10000000;j+=i)
                vis[j]=1;
        }
}
int main()
{
    int n,i;
    getprime();
    cin>>n;
    for(i=4;i<=n;i++)
    {
        if(vis[i]&&vis[n-i])
        {
            printf("%d %d\n",i,n-i);
            return 0;
        }
    }
}
// davidlee1999WTK 2014/
// srO myk Orz
//ios::sync_with_stdio(false);