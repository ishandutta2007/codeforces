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
typedef pair<int,int> pii;
int vis[100005];
int main()
{
    int T;
    T = 1;
    //cin>>T;
    while(T--)
    {
        int n, m, gcd, b, g, i, x, flag = 1;
        cin >> n >> m;
        gcd = __gcd(n,m);
        cin >> b;
        for(i = 1; i <= b; i++)
        {
            scanf("%d",&x);
            vis[x%gcd] = 1;
        }
        cin >> g;
        for(i = 1; i <= g; i++)
        {
            scanf("%d",&x);
            vis[x%gcd] = 1;
        }
        for(i=0;i<gcd;i++)
            if(!vis[i])
                flag = 0;
        if(flag)
            printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
// davidlee1999WTK 2017/
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
//#include<bits/stdc++.h>
/*

*/