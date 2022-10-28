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
#include<iomanip>
#include<deque>
#include<utility>
#include<functional>
#include<sstream>
#define INF 1000000000
#define fi first
#define se second
#define N 100005
#define P 1000000007
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
int a[N];
int main()
{
    int n, k;
    cin >> n >> k;
    int i, mn = INF;
    LL ans = 0;
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        mn = min(mn, a[i]);
    }
    for (i = 1; i <= n; i++)
        if ((a[i] - mn) % k != 0)
        {
            printf("-1\n");
            return 0;
        }
        else ans += (a[i] - mn) / k;
    cout << ans << endl;
}
// davidlee1999WTK 2017/
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
/*

*/