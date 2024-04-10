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
#define N 200005
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int a[N],b[N];
int main()
{
    int n,m1=0,m2=0,sum=0,i;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i],&b[i]);
        sum+=a[i];
        if(m1<b[i])
            m2=m1,m1=b[i];
        else if(b[i]>m2)
            m2=b[i];
    }
    //debug(m1);
    //debug(m2);
    for(i=1;i<n;i++)
        if(b[i]==m1)
            printf("%d ",(sum-a[i])*m2);
        else printf("%d ",(sum-a[i])*m1);
    if(b[i]==m1)
        printf("%d\n",(sum-a[i])*m2);
    else printf("%d\n",(sum-a[i])*m1);
    return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);