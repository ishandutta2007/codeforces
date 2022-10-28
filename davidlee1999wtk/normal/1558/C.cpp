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
#define N 200005
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int a[N];
vector<int> ans;
void solve(int n)
{
    int i, loc_n, l1;
    for(i=1;i<=n;i++)
        if(a[i] == n)
            loc_n = i;
    ans.push_back(loc_n);
    reverse(a+1, a+1+loc_n);
    for(i=1;i<=n;i++)
        if(a[i] == n-1)
            l1 = i;
    ans.push_back(l1-1);
    reverse(a+1, a+1+(l1-1));
    
    ans.push_back(l1+1);
    reverse(a+1, a+1+(l1+1));

    ans.push_back(3);
    reverse(a+1, a+1+3);

    ans.push_back(n);
    reverse(a+1, a+1+n);
}
int main()
{
    int T, n, i, flag;
    cin >> T;
    while(T--)
    {
        flag = 1;
        cin >> n;
        for(i=1;i<=n;i++)
        {
            scanf("%d", &a[i]);
            if(a[i] % 2 != i % 2)
            {
                flag = 0;
            }
        }
        if(flag == 0)
        {
            cout<<-1<<endl;
            continue;
        }
        ans.clear();
        for(i=n;i>1;i-=2)
        {
            solve(i);
        }
        cout<<ans.size()<<endl;
        for(auto x:ans)
        {
            printf("%d ", x);
        }
        cout<<endl;
    }
}
// davidlee1999WTK 2022/
// Team NewType, UT Austin
// srO myk Orz
//ios::sync_with_stdio(false);