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
#define N 100005
#define P 1000000007
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int main()
{
    int i,j,n,a,b,odd=1,even=2;
    cin>>n>>a>>b;
    if(n>a*b)
    {
        printf("-1\n");
        return 0;
    }
    for(i=1;i<=a;i++)
    {
        for(j=1;j<=b;j++)
            if((i+j)%2==0)
            {
                if(odd<=n)
                    printf("%d ",odd);
                else printf("0 ");
                odd+=2;
                //if(odd>n) odd=0;
            }
            else
            {
                if(even<=n)
                    printf("%d ",even);
                else printf("0 ");
                even+=2;
                //if(even>n) even=0;
            }
        cout<<endl;
    }
    return 0;
}
// davidlee1999WTK 2016/
// srO myk Orz
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000")