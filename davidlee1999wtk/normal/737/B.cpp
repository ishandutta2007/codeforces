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
#define N 200005
#define P 1000000007
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
char s[N];
int loc[N];
int main()
{
    int n,a,b,k,cnt=0,i,sum=0,j;
    cin>>n>>a>>b>>k;
    scanf("%s",s+1);
    loc[0]=0;
    loc[k+1]=n+1;
    for(i=1;i<=n;i++)
        if(s[i]=='1')
            loc[++cnt]=i;
    for(i=1;i<=k+1;i++)
        sum+=(loc[i]-loc[i-1]-1)/b;
    sum-=a;
    sum++;
    printf("%d\n",sum);
    for(i=1;i<=k+1&&sum;i++)
        if(loc[i]-loc[i-1]>b)
        {
            j=loc[i-1]+b;
            while(j<loc[i])
            {
                printf("%d ",j);
                sum--;
                if(sum==0)
                    break;
                j+=b;
            }
        }
    cout<<endl;
    return 0;
}
// davidlee1999WTK 2016/
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
/*

*/