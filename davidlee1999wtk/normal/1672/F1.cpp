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
int a[N], cnt[N], b[N], nb[N], bi[N];
int mp[N], fmp[N], cmp[N];
pii num[N];
vector<int> G[N];
int main()
{
    int T, i;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        for(i=1;i<=n;i++)
        {
            scanf("%d", &a[i]);
            cnt[i] = 0;
            cmp[i] = 0;
        }
        for(i=1;i<=n;i++)
            cnt[a[i]]++;
        for(i=1;i<=n;i++)
        {
            num[i].fi = cnt[i];
            num[i].se = i;
        }
        sort(num+1, num+1+n);
        reverse(num+1, num+1+n);
        for(i=1;i<=n;i++)
        {
            mp[num[i].se] = i;
            fmp[i] = num[i].se;
            G[i].clear();
        }
        for(i=1;i<=n;i++)
        {
            b[i] = mp[a[i]];
            bi[i] = 0;
            cmp[b[i]]++;
            G[b[i]].push_back(i);
        }
        int m = n;
        while(m)
        {
            int ls=1;
            for(i=1;i<=n;i++)
            {
                if(cmp[i] > bi[i])
                {
                    nb[G[i][bi[i]]] = i-1;
                    bi[i]++;
                    ls = i;
                }
                else
                    break;
            }
            nb[G[1][bi[1]-1]] = ls;
            m -= ls;
        }
        for(i=1;i<=n;i++)
            printf("%d ", fmp[nb[i]]);
        cout<<endl;
    }
}
// davidlee1999WTK 2022/
// Team NewType, UT Austin
// srO myk Orz
//ios::sync_with_stdio(false);