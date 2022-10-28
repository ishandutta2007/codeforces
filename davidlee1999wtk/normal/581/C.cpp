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
#define N 100005
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int a[N],b[N];
int main()
{
    int n,k,i,sum=0;
    cin>>n>>k;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i]/10;
        b[i]=10-a[i]%10;
    }
    sort(b+1,b+1+n);
    for(i=1;i<=n;i++)
    {
        if(k>=b[i]&&b[i]<10)
            sum++,k-=b[i];
        else break;
    }
    sum+=k/10;
    cout<<min(sum,n*10)<<endl;
    return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000")
//#define O2 __attribute__((optimize("-O2")))