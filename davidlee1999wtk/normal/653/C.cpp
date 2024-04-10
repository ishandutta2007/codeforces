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
#define N 150005
#define P 1000000007
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int b[N],l[N];
bool check(int x)
{
    if(x%2==0)
        if(b[x]>b[x-1]&&b[x]>b[x+1])
            return 1;
        else return 0;
    else
    {
        //debug(b[x]);
        //debug(b[x-1]);
        //debug(b[x+1]);
        if(b[x]<b[x-1]&&b[x]<b[x+1])
            return 1;
        else return 0;
    }
}
int main()
{
    int n,loc=0,i,j,ans=0,m=0;
    cin>>n;
    b[0]=INF;
    if(n%2==0)
        b[n+1]=-1;
    else b[n+1]=INF;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&b[i]);//,b[i]=a[i];
        if(i%2==0)
            if(b[i]<=b[i-1])
                loc=i-1,l[++m]=i;
        if(i%2==1)
            if(b[i]>=b[i-1])
                loc=i-1,l[++m]=i;
    }
    if(m>4)
    {
        printf("0\n");
        return 0;
    }
    for(i=1;i<=n;i++)
        if(i!=loc&&i!=loc+1)
        {
            swap(b[i],b[loc]);
            //debug(b[4]);
            //de
            //if(i==2)
                //debug(check(5));
            if(check(i)&&check(loc))
            {
                //if(i==2)
                    //debug(check(5));
                for(j=1;j<=m;j++)
                    if(!check(l[j]))
                        break;
                if(j==m+1)
                {
                    //debug(i);
                    //debug(loc);
                    ans++;
                }
            }
            swap(b[i],b[loc]);
        }
    loc++;
    for(i=1;i<=n;i++)
        if(i!=loc)
        {
            swap(b[i],b[loc]);
            if(check(i)&&check(loc))
            {
                for(j=1;j<=m;j++)
                    if(!check(l[j]))
                        break;
                if(j==m+1)
                {
                    //debug(i);
                    ans++;
                }
            }
            swap(b[i],b[loc]);
        }
    cout<<ans<<endl;
    return 0;
}
// davidlee1999WTK 2016/
// srO myk Orz
//ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000")
//#define O2 __attribute__((optimize("-O2")))