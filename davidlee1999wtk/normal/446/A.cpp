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
int a[100005],l[100005],r[100005];
int main()
{
    int n,i,cou=0,ans=0;
    cin>>n;
    a[0]=0;
    a[n+1]=0;
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=n;i++)
    {
        if(a[i]>a[i-1])
        {
            cou++;
            l[i]=cou;
        }
        else
            cou=1,l[i]=cou;
    }
    cou=0;
    for(i=n;i>=1;i--)
    {
        if(a[i]<a[i+1])
        {
            cou++;
            r[i]=cou;
        }
        else
            cou=1,r[i]=cou;
    }
    for(i=1;i<=n;i++)
    {
        if(a[i-1]+1<a[i+1])
            ans=max(ans,l[i-1]+1+r[i+1]);
        else
        {
            ans=max(ans,l[i-1]+1);
            ans=max(ans,r[i+1]+1);
        }
    }
    cout<<ans<<endl;
    return 0;
}
// davidlee1999WTK 2014/
// srO myk Orz
//ios::sync_with_stdio(false);