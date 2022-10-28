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
using namespace std;
typedef long long LL;
LL a[105],sum,c[105];
int b[105];
int main()
{
    int n,m,i;
    cin>>n>>m;
    for(i=1;i<=n;i++)
        cin>>a[i],sum+=a[i];
    for(i=1;i<=m;i++)
    {
        cin>>b[i];
        sum-=a[b[i]]; c[i]=a[b[i]];
    }
    sort(c+1,c+1+m);
    for(i=m;i;i--)
        sum+=max(sum,c[i]);
    cout<<sum<<endl;
    return 0;
}
// davidlee1999WTK 2014/
// srO myk Orz
//ios::sync_with_stdio(false);