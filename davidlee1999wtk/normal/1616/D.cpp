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
int a[N];
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n, i;
        int ans = 0;
        int mar, op = 0;
        cin >> n;
        for(i=1;i<=n;i++)
            scanf("%d", &a[i]);
        int x;
        cin >> x;
        for(i=1;i<=n;i++)
            a[i] -= x;
        for(i=1;i<=n;i++)
        {
            if(op == 0)
            {
                ans ++;
                op = 1;
                mar = a[i];
            }
            else
            {
                if(a[i] >= 0)
                {
                    if(mar < 0)
                    {
                        if(a[i] + mar >= 0)
                        {
                            op = 1;
                            ans ++;
                            mar = a[i] + mar;
                        }
                        else
                        {
                            op = 0;
                        }
                    }
                    else
                    {
                        op = 1;
                        ans ++;
                        mar = a[i];
                    }
                }
                else if(a[i] < 0)
                {
                    if(mar < 0)
                    {
                        op = 0;
                    }
                    else
                    {
                        if(mar + a[i] >= 0)
                        {
                            op = 1;
                            ans ++;
                            mar = a[i];
                        }
                        else
                        {
                            op = 0;
                        }
                    }
                }
            }
            //debug(i);
            //debug(op);
            //debug(mar);
        }
        cout << ans << endl;
    }
}
// davidlee1999WTK 2022/
// srO myk Orz
//ios::sync_with_stdio(false);