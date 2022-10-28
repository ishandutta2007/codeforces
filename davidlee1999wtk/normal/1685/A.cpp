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
int a[N], b[N];

int main()
{
    int T, n;
    cin >> T;
    while(T--)
    {
        cin >> n;
        int i;
        for(i=1;i<=n;i++)
        {
            scanf("%d", &a[i]);
        }
        if(n % 2 == 1)
        {
            printf("NO\n");
            continue;
        }
        sort(a+1,a+1+n);
        reverse(a+1, a+1+n);
        b[0] = a[n];
        int flag = 1;
        for(i=1;i<=n/2;i++)
        {
            b[i*2 - 1] = a[i];
            b[i*2] = a[i + n/2];
            if(a[i] <= b[i*2 - 2])
            {
                flag = 0;
            }
        }
        if(flag == 0)
        {
            printf("NO\n");
            continue;
        }
        else
        {
            printf("YES\n");
            for(i=1;i<=n;i++)
                printf("%d ", b[i]);
            cout<<endl;
        }
    }
}
// davidlee1999WTK 2022/
// Team NewType, UT Austin
// srO myk Orz
//ios::sync_with_stdio(false);