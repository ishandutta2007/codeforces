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
int main()
{
    int n, ans, l = 1, r, mid, rel;
    cin >> n;
    r = n * 2001;
    while(l < r)
    {
        mid = (l+r) >> 1;
        printf("? %d\n", mid);
        fflush(stdout);
        cin >> rel;
        //debug(rel);
        if(rel == 0 || rel > 1)
        {
            l = mid+1;
        }
        else
        {
            r = mid;
        }
    }
    ans = l;
    int q, i;
    for(i=2;i<=n;i++)
    {
        q = ans / i;
        if(ans % i == 0)
            q--;
        printf("? %d\n", q);
        fflush(stdout);
        cin >> rel;
        if(rel != 0 && rel <= i)
            ans = rel * q;
    }
    printf("! %d\n", ans);
    fflush(stdout);
}
// davidlee1999WTK 2022/
// Team NewType, UT Austin
// srO myk Orz
//ios::sync_with_stdio(false);