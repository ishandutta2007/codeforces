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
int n,m,a[N],cnt[N];
vector<int> G;
int main()
{
    cin>>n>>m;
    int i,j,ans,k;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]<=m)
            cnt[a[i]]++;
    }
    k=n/m;
    for(i=1;i<=m;i++)
        for(j=1;j<=k-cnt[i];j++)
            G.push_back(i);
    cout<<k<<' '<<G.size()<<endl;
    for(i=1,j=0;i<=n,j<G.size();i++)
        if(a[i]<=m)
        {
            if(cnt[a[i]]>k)
            {
                cnt[a[i]]--;
                a[i]=G[j];
                j++;
            }
        }
        else
        {
            a[i]=G[j];
            j++;
        }
    for(i=1;i<=n;i++)
        printf("%d ",a[i]);
    return 0;
}
// davidlee1999WTK 2016/
// srO myk Orz
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
/*

*/