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
int vis[105];
int main()
{
    int n;
    int T;
    cin >> T;
    while(T--)
    {
        cin >> n;
        memset(vis, 0, sizeof(vis));
        int i, a;
        for(i=1;i<=n;i++)
        {
            cin >> a;
            vis[abs(a)]++;
        }
        int ans = 0;
        for(i=1;i<=100;i++)
            ans += min(vis[i], 2);
        ans += min(1, vis[0]);
        cout<<ans<<endl;
    }
    return 0;
}
// davidlee1999WTK 2022/
// srO myk Orz
//ios::sync_with_stdio(false);