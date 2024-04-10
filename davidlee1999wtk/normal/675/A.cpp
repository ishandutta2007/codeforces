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
int main()
{
    LL a,b,c;
    cin>>a>>b>>c;
    if(c<0)
    {
        swap(a,b);
        c*=-1;
    }
    if(c==0)
    {
        if(a==b)
            printf("YES\n");
        else printf("NO\n");
        return 0;
    }
    if((b-a)%c==0&&(b-a)/c>=0)
        printf("YES\n");
    else printf("NO\n");
    return 0;
}
// davidlee1999WTK 2016/
// srO myk Orz
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++