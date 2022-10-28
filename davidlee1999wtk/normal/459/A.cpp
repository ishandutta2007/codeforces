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
    int k,x1,x2,y1,y2;
    cin>>x1>>y1>>x2>>y2;
    if(abs(x1-x2)==abs(y1-y2)&&x1!=x2&&y1!=y2)
    {
        printf("%d %d %d %d\n",x1,y2,x2,y1);
    }
    else if(x1==x2)
    {
        k=abs(y1-y2);
        printf("%d %d %d %d\n",x1+k,y1,x1+k,y2);
    }
    else if(y1==y2)
    {
        k=abs(x1-x2);
        printf("%d %d %d %d\n",x1,y1+k,x2,y1+k);
    }
    else printf("-1\n");
    return 0;
}
// davidlee1999WTK 2014/
// srO myk Orz
//ios::sync_with_stdio(false);