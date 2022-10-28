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
int a[2005];
int main()
{
    int n,k,i,j,ans=0;
    cin>>n>>k;
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    for(i=n;i>0;i-=k)
    {
        ans+=(a[i]-1)*2;
    }
    cout<<ans<<endl;
    return 0;
}
// davidlee1999WTK 2014/
// srO myk Orz
//ios::sync_with_stdio(false);