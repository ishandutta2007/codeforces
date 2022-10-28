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
#define N 400005
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
char s[N];
int a[N];
int main()
{
    int T, n, i;
    cin >> T;
    while(T--)
    {
        int flag = 0, l = 0, r, ml = -1, mr = -1, mm = -1, li, ri, mi;
        cin >> n;
        n <<= 1;
        a[0] = 0;
        scanf("%s", s+1);
        for(i=1;i<=n;i++)
            if(s[i] == '(')
                a[i] = a[i-1] + 1;
            else
                a[i] = a[i-1] - 1;
        for(i=1;i<=n;i++)
            if(a[i] < 0)
            {
                if(!l)
                    l = i;
                flag = 1;
                r = i;
            }
        if(flag == 0)
        {
            printf("0\n");
            continue;
        }
        for(i=0;i<=l;i++)
        {
            if(ml < a[i])
            {
                ml = a[i];
                li = i;
            }
        }
        for(i=l;i<=r;i++)
            if(mm < a[i])
                {
                    mm = a[i];
                    mi = i;
                }
        for(i=r;i<=n;i++)
            if(mr < a[i])
            {
                mr = a[i];
                ri = i;
            }
        if(ml + mr >= mm)
        {
            printf("1\n");
            printf("%d %d\n", li+1, ri);
        }
        else
        {
            printf("2\n");
            printf("%d %d\n", li+1, mi);
            printf("%d %d\n", mi+1, ri);
        }
    }
}
// davidlee1999WTK 2022/
// Team NewType, UT Austin
// srO myk Orz
//ios::sync_with_stdio(false);