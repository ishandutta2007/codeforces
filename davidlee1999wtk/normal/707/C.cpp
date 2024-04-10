#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<utility>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<queue>
#include<stack>
#include<bitset>
#include<ctime>
#include<deque>
#define N 100005
#define P 1000000007
#define INF 1000000000
#define fi first
#define se second
#define debug(x) cerr<<#x<<' '<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
int main()
{
    LL n,m,k,C=1;
    cin>>n;
    if(n<=2)
    {
        printf("-1\n");
        return 0;
    }
    if(n&1)
        cout<<n*n/2<<' '<<n*n/2+1<<endl;
    else
    {
        while(n%2==0&&n>4)
            n/=2,C*=2;
        if(n==4)
            cout<<3*C<<' '<<5*C<<endl;
        else
            cout<<n*n/2*C<<' '<<(n*n/2+1)*C<<endl;
    }
    return 0;
}