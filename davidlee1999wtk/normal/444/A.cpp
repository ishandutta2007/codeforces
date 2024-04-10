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
double s[505];
int main()
{
    int n,m,i,a,b;
    double c;
    double mi=0;
    cin>>n>>m;
    for(i=1;i<=n;i++)
        scanf("%lf",&s[i]);
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%lf",&a,&b,&c);
        if((s[a]+s[b])/c>mi)
            mi=(s[a]+s[b])/c;
    }
    printf("%.15f\n",mi);
    return 0;
}
// davidlee1999WTK 2014/
// srO myk Orz
//ios::sync_with_stdio(false);