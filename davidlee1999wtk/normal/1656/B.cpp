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
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n, k, i, j;
        cin >> n >> k;
        for(i=1;i<=n;i++)
            scanf("%d", &a[i]);
        sort(a+1, a+1+n);
        int flag = 0;
        for(i=1, j = 1; i<=n && j <= n ;i++)
        {
            while(a[j] - a[i] < k && j <= n)
            {
                j++;
            }
            if(j == n+1)
                break;
            if(a[j] - a[i] == k)
            {
                flag = 1;
            }
        }
        if(flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}
// davidlee1999WTK 2022/
// Team NewType, UT Austin
// srO myk Orz
//ios::sync_with_stdio(false);