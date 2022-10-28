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
#define N 200005
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
LL a[N], b[N];
int main()
{
    int T, i;
    cin >> T;
    while(T--)
    {
        int n, k;
        LL offset, ans = 0;
        cin >> n >> k;
        offset = LL(k)* (k+1) / 2;
        for(i=1;i<=n;i++)
        {
            scanf("%d", &a[i]);
            ans += a[i];
            b[i] = (n-i+1) - a[i];
            //debug(b[i]);
        }
        //debug(offset);
        //debug(ans);
        sort(b+1, b+1+n);
        for(i=1;i<=k;i++)
            ans += b[i];
        ans -= offset;
        cout<<ans<<endl;
    }
}
// davidlee1999WTK 2022/
// Team NewType, UT Austin
// srO myk Orz
//ios::sync_with_stdio(false);