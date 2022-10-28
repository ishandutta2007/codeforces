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
#define N 500005
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int a[N];
int main()
{
    int ans=0,i,n,cnt,l,r;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    cnt=0;
    a[0]=a[1];
    a[n+1]=a[n];
    n++;
    for(i=1;i<=n;i++)
    {
        //debug(cnt);
        if(a[i]!=a[i-1])
            cnt++;
        else
        {
            ans=max(ans,cnt/2);
            if(cnt>=2)
            {
                if(cnt%2==0)
                    for(r=i;r>=i-cnt;r--)
                        a[r]=a[i];
                else
                {
                    l=i-cnt-2;
                    r=i;
                    for(;r>l;r--,l++)
                        a[r]=a[i],a[l]=a[i-cnt-2];
                }
            }
            cnt=0;
        }
    }
    //ans=max(ans,cnt/2);
    cout<<ans<<endl;
    for(i=1;i<=n-1;i++)
        printf("%d ",a[i]);
    return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000")
//#define O2 __attribute__((optimize("-O2")))