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
#define N 105
#define P 1000000007
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
struct Team
{
    int p1,p2,num;
    bool operator<(const Team &x) const
    {
        if(p1==x.p1)
            return num<x.num;
        else return p1>x.p1;
    }
}t[N];
int main()
{
    int n,i,j,ans=0,k;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&t[i].p1,&t[i].p2);
        t[i].num=i;
    }
    sort(t+1,t+1+n);
    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
            if(t[i].p2<0)
            {
                t[i].p1+=t[i].p2;
                t[i].p2=0;
                for(j=i+1;j<=n;j++)
                    if(t[j]<t[j-1])
                    {
                        ans++;
                        swap(t[j],t[j-1]);
                    }
                //debug(ans);
                break;
            }
    }
    //debug(ans);
    for(k=1;k<=n;k++)
    {
        for(i=n;i;i--)
            if(t[i].p2>0)
            {
                t[i].p1+=t[i].p2;
                t[i].p2=0;
                for(j=i;j>1;j--)
                    if(t[j]<t[j-1])
                    {
                        ans++;
                        swap(t[j],t[j-1]);
                    }
                //debug(ans);
                break;
            }
    }
    cout<<ans<<endl;
    return 0;
}
// davidlee1999WTK 2016/
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
/*

*/