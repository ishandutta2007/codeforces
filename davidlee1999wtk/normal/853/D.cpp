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
#define N 300005
#define P 1000000007
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int a[N];
int pre_sum[N];
int main()
{
    int n, sum = 0, x, y, z, now, last_K, i;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        sum += a[i];
        pre_sum[i] = sum;
    }
    y = sum / 1100 * 100;
    z = sum % 1100;
    debug(sum);
    debug(z);
    if(z==1000)
    {
        printf("%d\n",sum-y);
        //return 0;
    }
    else
    {
        x = y * 10;
        last_K = -1;
        now = 0;
        for(i=1;i<=n;i++)
        {
            if(now + a[i] > x)
                continue;
            else
                now+=a[i];
            if(now == x)
                break;
            if(a[i] == 1000)
                last_K = i;
        }
        if(i > n || i== n)
        {
            if(last_K == -1)
                printf("%d\n",sum - (y-100));
            else
            {
                if(pre_sum[last_K - 1] >= 10000 - z * 10)
                    printf("%d\n",sum - y);
                else
                    printf("%d\n",sum - (y-100));
            }
        }
        else
        {
            printf("%d\n",sum - y);
            //return 0;
        }
    }
    return 0;
}
// davidlee1999WTK 2017/
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
//#include<bits/stdc++.h>
/*
8
2000 1000 2000 1000 2000 2000 2000 1000
*/