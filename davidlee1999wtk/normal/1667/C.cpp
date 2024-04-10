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
#define N 100005
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
void solve(int k)
{
    int d = 1,i, t= k/2+1;
    for(i=1;i<=t;i++)
        printf("%d %d\n", i, t-i+1);
    for(i=t+1;i<=k;i++)
        printf("%d %d\n", i, k - i + t+1 );
}
int main()
{
    int n, m, i, k;
    cin >> n;
    if(n==1)
    {
        cout<<1<<endl;
        cout<<"1 1"<<endl;
        return 0;
    }
    if(n % 3 == 0)
    {
        m = n - (n/3);
        k = m-1;
    }
    else if(n % 3 == 1)
    {
        m = n - (n/3);
        k = m-2;
    }
    else
    {
        m = n - (n+1)/3;
        k = m;
    }
    cout<<m<<endl;
    solve(k);
    for(i=k+1;i<=m;i++)
        printf("%d %d\n", i, i);
    return 0;
}
// davidlee1999WTK 2022/
// Team NewType, UT Austin
// srO myk Orz
//ios::sync_with_stdio(false);