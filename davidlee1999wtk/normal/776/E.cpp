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
int pri[2000005],vis[2000005]={0};
void getprime()
{
    int i,j;
    for(i=2;i<=2000000;i++)
        if(!vis[i])
        {
            pri[++cou]=i;
            for(j=i+i;j<=2000000;j+=i)
                vis[j]=1;
        }
}

LL phi2(LL x)
{
    LL ans=x,i,y;
    for(i=1;y=pri[i],y*y<=x;i++)
    {
        if(x%y==0)
        {
            ans=ans/y*(y-1);
            while(x%y==0) x/=y;
        }
    }
    if(x>1)
        ans=ans/x*(x-1);
    return ans;
}

int main()
{
    getprime();
    LL n,k,ans;
    cin>>n>>k;
    ans=phi2(n);
    k--;
    k/=2;
    while(k--)
    {
        ans=phi2(ans);
        if(ans==1)
            break;
    }
    cout<<ans%P<<endl;
    return 0;
}
// davidlee1999WTK 2017/
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
/*

*/