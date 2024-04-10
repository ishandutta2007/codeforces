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
#define INF 1000000000
#define N 1000005
#define P 1000000007
#define fi first
#define se second
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int p[N];
int G[N];
int main()
{
    int n, i, bg=0, ls=0;
    LL sum = 0, ans;
    cin>>n;
    ans = (LL)n*n;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&p[i]);
        sum+=abs(p[i]-i);
        if(p[i]>i)
            bg++;
        else ls++;
        if(p[i]>1)
        {
            if(p[i]<=i)
                G[p[i]+(n-i)]++;
            else G[p[i]-i]++;
        }
    }
    int rot = 0;
    ans = sum;
    for(i=1;i<n;i++)
    {
        sum-=bg;
        sum+=ls;
        sum-=abs(n+1-p[n-i+1]);
        sum+=abs(p[n-i+1]-1);
        if(p[n-i+1]>1)
        {
            ls--;
            bg++;
        }
        bg-=G[i];
        ls+=G[i];
        if(sum<ans)
            ans = sum, rot = i;
        //ans=min(ans,sum);
    }
    cout<<ans<<" "<<rot<<endl;
}
// davidlee1999WTK 2016/
// srO myk Orz
//ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000")  //compiler vc++
//#define O2 __attribute__((optimize("-O2")))