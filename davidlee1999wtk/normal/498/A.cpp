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
#define INF 100000000
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
LL a,b,c;
int main()
{
    int n,i,ans=0;
    LL r1,r2,c1,c2,t1,t2;
    cin>>r1>>c1>>r2>>c2;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a>>b>>c;
        t1=(r1*a+c1*b+c);
        t2=(r2*a+c2*b+c);
        if(t1>0&&t2<0||t1<0&&t2>0)
            ans++;
    }
    cout<<ans<<endl;
    return 0;
}
// davidlee1999WTK 2014/
// srO myk Orz
//ios::sync_with_stdio(false);