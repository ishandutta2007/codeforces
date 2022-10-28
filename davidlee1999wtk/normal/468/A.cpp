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
#define INF 100000000
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int main()
{
    int n;
    cin>>n;
    if(n<=3) printf("NO\n");
    else if(n==4)
    {
        printf("YES\n");
        printf("1 * 2 = 2\n");
        printf("2 * 3 = 6\n");
        printf("6 * 4 = 24\n");
    }
    else if(n==5)
    {
        printf("YES\n");
        printf("5 - 1 = 4\n");
        printf("4 - 2 = 2\n");
        printf("2 * 3 = 6\n");
        printf("6 * 4 = 24\n");
    }
    else
    {
        printf("YES\n");
        printf("3 - 2 = 1\n");
        printf("1 - 1 = 0\n");
        for(int i=7;i<=n;i++)
            printf("%d * 0 = 0\n",i);
        printf("5 * 0 = 0\n");
        printf("0 + 4 = 4\n");
        printf("4 * 6 = 24\n");
    }
    return 0;
}
// davidlee1999WTK 2014/
// srO myk Orz
//ios::sync_with_stdio(false);