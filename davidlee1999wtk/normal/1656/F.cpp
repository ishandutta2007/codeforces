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
LL a[N];
LL solve(int n)
{
    int i;
    LL sum = 0, cost = 0;
    sort(a+1, a+1+n);
    for(i=2;i<=n;i++)
    {
        sum += a[i];
        cost += a[i] * a[1];
    }
    sum += a[1] * (n-1);
    if(sum > 0)
        return LL(INF) * INF;
    // case of n = 2?
    for(i=2;i<=n;i++)
    {
        if(a[i] >= 0)
            break;
        if(sum + (a[n] - a[1]) <= 0)
        {
            sum += (a[n] - a[1]);
            cost += a[i] * (a[n] - a[1]);
            continue;
        }
        else
            return cost + a[i] * (-sum);
    }
    return cost;
}
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n, i;
        cin >> n;
        for(i=1;i<=n;i++)
            scanf("%I64d", &a[i]);
        LL ans_1, ans_2;
        ans_1 = solve(n);
        for(i=1;i<=n;i++)
            a[i] = -1 * a[i];
        ans_2 = solve(n);
        //debug(ans_1);
        //debug(ans_2);
        if(ans_1 == LL(INF) * INF || ans_2 == LL(INF) * INF)
            cout<<"INF"<<endl;
        else
            cout<<max(ans_1, ans_2)<<endl;
    }
    return 0;
}
// davidlee1999WTK 2022/
// Team NewType, UT Austin
// srO myk Orz
//ios::sync_with_stdio(false);