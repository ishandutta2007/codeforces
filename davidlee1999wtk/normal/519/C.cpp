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
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int main()
{
    int n,m,ans=0;
    cin>>n>>m;
    while(n>0&&m>0)
    {
        if(n>m) swap(n,m);
        if(n<1||m<2) break;
        n-=1,m-=2;
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);