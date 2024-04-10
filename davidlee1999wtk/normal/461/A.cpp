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
#define INF 100000000
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int a[300005];
int main()
{
    int n,i;
    LL ans=0,sum=0;
    cin>>n;
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]),ans+=a[i];
    sort(a+1,a+1+n);
    sum=ans;
    for(i=1;i<n;i++)
    {
        ans+=sum;
        sum-=a[i];
    }
    cout<<ans<<endl;
    return 0;
}
// davidlee1999WTK 2014/
// srO myk Orz
//ios::sync_with_stdio(false);