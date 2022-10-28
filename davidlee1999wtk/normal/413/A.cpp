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
using namespace std;
typedef long long LL;
int main()
{
    int maxt,mint,n,a,m,flag=2,i;
    cin>>n>>m>>mint>>maxt;
    for(i=1;i<=m;i++)
    {
        scanf("%d",&a);
        if(a==maxt) flag--;
        else if(a==mint) flag--;
        if(a>maxt||a<mint) flag=INF;
    }
    if(flag<=n-m) printf("Correct\n");
    else printf("Incorrect\n");
    return 0;
}
// davidlee1999WTK 2014/
// srO myk Orz
//ios::sync_with_stdio(false);