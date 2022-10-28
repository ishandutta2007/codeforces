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
int mul=233,P=1020407;
struct Hash
{
    int x,y,pre;
}hs[1100000];
pii a[100005];
int h[1100000],num[2100000];
inline bool get(int x,int y)
{
    int o=x*mul+y;
    o%=P;
    int i;
    for(i=h[o];i;i=hs[i].pre)
        if(hs[i].x==x&&hs[i].y==y)
            return 1;
    return 0;
}
int main()
{
    int n,i,sq,j,k1,k2,ans=0,bc;
    int x;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i].fi,&a[i].se);
        a[i].fi+=1000000; a[i].se+=1000000;
        num[a[i].fi]++;
        x=a[i].fi*mul+a[i].se;
        x%=P;
        hs[i]=(Hash){a[i].fi,a[i].se,h[x]};
        h[x]=i;
    }
    sort(a+1,a+1+n);
    sq=(int)sqrt(double(n)+0.5);
    for(i=1;i<=n;)
    {
        for(j=i+1;a[j].fi==a[i].fi&&j<=n;j++);
        j--;
        if(num[a[i].fi]<=sq)
            for(k1=i;k1<=j;k1++)
                for(k2=k1+1;k2<=j;k2++)
                {
                    bc=(a[k2].se-a[k1].se);
                    if(get(a[k1].fi-bc,a[k1].se)&&get(a[k2].fi-bc,a[k2].se))
                        ans++;
                }
        else
            for(k1=1;k1<i;k1++)
            {
                bc=(a[i].fi-a[k1].fi);
                if(get(a[k1].fi,bc+a[k1].se)&&get(a[i].fi,a[k1].se)&&get(a[i].fi,bc+a[k1].se))
                    ans++;
            }
        i=j+1;
    }
    cout<<ans<<endl;
    return 0;
}
// davidlee1999WTK 2014/
// srO myk Orz
//ios::sync_with_stdio(false);