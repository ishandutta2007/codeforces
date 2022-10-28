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
pii e[5005];
int main()
{
    int n,i,now;
    cin>>n;
    for(i=1;i<=n;i++)
        scanf("%d%d",&e[i].fi,&e[i].se);
    sort(e+1,e+1+n);
    now=0;
    for(i=1;i<=n;i++)
    {
        if(e[i].se>=now)
            now=e[i].se;
        else now=e[i].fi;
    }
    cout<<now<<endl;
    return 0;
}
// davidlee1999WTK 2014/
// srO myk Orz
//ios::sync_with_stdio(false);