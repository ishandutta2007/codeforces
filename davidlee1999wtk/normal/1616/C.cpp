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
int a[75];
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        int i;
        for(i=1;i<=n;i++)
            scanf("%d", &a[i]);
        int d, k, ans = 0, l;
        for(d = -200; d <= 200; d++)
        {
            for(l=1;l<=n;l++)
                for(k = 1; k <= n; k++)
                {
                    int cnt = 1;
                    for(i=k+l;i<=n;i+=l)
                    {
                        if(abs(a[k] + d * ((i-k)/l)) >= 101)
                            break;
                        if(a[i] == a[k] + d * ((i-k)/l))
                            cnt ++;
                    }
                    ans = max(ans, cnt);
                }
        }
        cout<<n-ans<<endl;


    }
}
// davidlee1999WTK 2022/
// srO myk Orz
//ios::sync_with_stdio(false);