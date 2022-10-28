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
LL c,hr,hb,wr,wb,lcm,sz,l;
int main()
{
    LL i,ans=0;
    cin>>c>>hr>>hb>>wr>>wb;
    sz=sqrt(c+0.5);
    if(wr>sz)
    {
        for(i=0;wr*i<=c;i++)
            ans=max(ans,i*hr+(c-i*wr)/wb*hb);
    }
    else if(wb>sz)
    {
        for(i=0;wb*i<=c;i++)
            ans=max(ans,i*hb+(c-i*wb)/wr*hr);
    }
    else
    {
        lcm=wr*wb/__gcd(wr,wb);
        if(lcm/wr*hr>=lcm/wb*hb)
        {
            l=lcm/wb;
            for(i=0;i<=l;i++)
                ans=max(ans,i*hb+(c-i*wb)/wr*hr);
        }
        else
        {
            l=lcm/wr;
            for(i=0;i<=l;i++)
                ans=max(ans,i*hr+(c-i*wr)/wb*hb);
        }
    }
    cout<<ans<<endl;
    return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);