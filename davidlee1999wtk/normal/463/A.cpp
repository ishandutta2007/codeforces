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
int main()
{
    int n,s,i,x,y,ans=-1;
    cin>>n>>s;
    s*=100;
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&x,&y);
        x*=100;
        if(s<x+y) continue;
        else ans=max(ans,(100-y)%100);
    }
    cout<<ans<<endl;
    return 0;
}
// davidlee1999WTK 2014/
// srO myk Orz
//ios::sync_with_stdio(false);