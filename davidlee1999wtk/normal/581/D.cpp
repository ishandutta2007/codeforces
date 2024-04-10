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
struct Logo
{
    int fi,se,num;
    bool operator<(const Logo a) const
    {
        return MP(fi,se)>MP(a.fi,a.se);
    }
}lg[4];
int main()
{
    int i,j,n,r,c1,c2,c3,sum=0;
    for(i=1;i<=3;i++)
    {
        cin>>lg[i].fi>>lg[i].se;
        if(lg[i].fi<lg[i].se)
            swap(lg[i].fi,lg[i].se);
        sum+=lg[i].fi*lg[i].se;
        lg[i].num=i;
    }
    n=sqrt(sum+0.5);
    if(n*n!=sum)
    {
        printf("-1\n");
        return 0;
    }
    sort(lg+1,lg+1+3);
    if(lg[1].fi!=n)
    {
        printf("-1\n");
        return 0;
    }
    c1=lg[1].se;
    if(lg[2].fi==n&&lg[3].fi==n)
    {
        cout<<n<<endl;
        c2=lg[2].se;
        c3=lg[3].se;
        for(i=1;i<=c1;i++)
        {
            for(j=1;j<=n;j++)
                printf("%c",64+lg[1].num);
            cout<<endl;
        }
        for(i=1;i<=c2;i++)
        {
            for(j=1;j<=n;j++)
                printf("%c",64+lg[2].num);
            cout<<endl;
        }
        for(i=1;i<=c3;i++)
        {
            for(j=1;j<=n;j++)
                printf("%c",64+lg[3].num);
            cout<<endl;
        }
    }
    else
    {
        r=n-c1;
        for(i=2;i<=3;i++)
            if(lg[i].fi==r||lg[i].se==r)
            {
                if(lg[i].se==r)
                    swap(lg[i].fi,lg[i].se);
            }
            else
            {
                printf("-1\n");
                return 0;
            }
        cout<<n<<endl;
        c2=lg[2].se;
        for(i=1;i<=c1;i++)
        {
            for(j=1;j<=n;j++)
                printf("%c",64+lg[1].num);
            cout<<endl;
        }
        for(i=1;i<=r;i++)
        {
            for(j=1;j<=n;j++)
                if(j<=c2)
                    printf("%c",64+lg[2].num);
                else printf("%c",64+lg[3].num);
            cout<<endl;
        }
    }
    return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000")
//#define O2 __attribute__((optimize("-O2")))