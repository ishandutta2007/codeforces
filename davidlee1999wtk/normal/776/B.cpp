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
int cou;
int pri[1000005],vis[10000005]={0};
void getprime()
{
    int i,j;
    for(i=2;i<=10000000;i++)
        if(!vis[i])
        {
            pri[++cou]=i;
            for(j=i+i;j<=10000000;j+=i)
                vis[j]=1;
        }
}
int main()
{
    getprime();
    int n,i;
    cin>>n;
    if(n<=2)
    {
        cout<<1<<endl;
        for(i=2;i<=n+1;i++)
            printf("%d ",1);
    }
    else
    {
        cout<<2<<endl;
        for(i=2;i<=n+1;i++)
            printf("%d ",vis[i]+1);
    }
    return 0;
}
// davidlee1999WTK 2017/
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
/*

*/