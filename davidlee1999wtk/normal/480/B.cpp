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
map<LL,int> mp;
int a[100005];
int main()
{
    int n,l,i,fx=0,fy=0,fxy=0,fyx=0,l2;
    LL x,y,loc;
    cin>>n>>l>>x>>y;
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]),mp[a[i]]=1;
    for(i=1;i<=n;i++)
    {
        if(mp[a[i]+x]==1)
            fx=1;
        if(mp[a[i]+y]==1)
            fy=1;
        if(mp[x+y+a[i]]==1)
            fxy=1,loc=a[i]+x;
        if(!fyx&&mp[y-x+a[i]])
        {
            l2=a[i]+y;
            if(l2<=l)
            {
                fyx=1;
                continue;
            }
            l2=a[i]-x;
            if(l2>=0)
            {
                fyx=1;
                continue;
            }
        }
    }
    if(fx&&fy) printf("0\n");
    else if(fx!=0&&fy==0)
        printf("1\n%d\n",int(y));
    else if(fx==0&&fy!=0)
        printf("1\n%d\n",int(x));
    else if(fxy)
        printf("1\n%d\n",int(loc));
    else if(fyx)
        printf("1\n%d\n",int(l2));
    else
        printf("2\n%d %d\n",(int)x,(int)y);
    return 0;
}
// davidlee1999WTK 2014/
// srO myk Orz
//ios::sync_with_stdio(false);
/*
2 1000000000 99999998 99999999
0 1000000000
*/