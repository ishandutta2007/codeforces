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
    int n,a,b,c1=0,c2=0;
    cin>>n;
    while(n--)
    {
        cin>>a>>b;
        if(a>b)
            c1++;
        if(b>a)
            c2++;
    }
    if(c1>c2)
        printf("Mishka\n");
    else if(c1==c2)
        printf("Friendship is magic!^^\n");
    else printf("Chris\n");
    return 0;
}
// davidlee1999WTK 2016/
// srO myk Orz
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++