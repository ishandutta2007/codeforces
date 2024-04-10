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
#include<ctime>
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
LL a[N], b[N];
int main()
{
    int i, n, m;
    LL ans, sum, sa = 0, sb = 0;
    cin >> n >> m;
    for (i = 1; i <= n; i++)
    {
        scanf("%I64d", &a[i]), sa += a[i];
        //debug(a[i]);
    }
    for (i = 1; i <= m; i++)
    {
        scanf("%I64d", &b[i]), sb += b[i];
        //debug(b[i]);
        //debug(sa);
    }
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + m);
    sum = sa;
    for (i = 1; i < m; i++)
        sum += min(b[i], sa);
    ans = sum;

    sum = sb;
    for (i = 1; i < n; i++)
        sum += min(a[i], sb);
    ans = min(ans, sum);
    cout << ans << endl;
    return 0;
}
// davidlee1999WTK 2017/
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
//#include<bits/stdc++.h>
/*
3 4
278848730 337369924 654933675
350303294 732544605 866361693 890800310
*/