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
int a[N];
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n, max_i, min_i, max_v= 0, min_v = INF+1;
        cin >> n;
        for(int i=1;i<=n;i++)
        {
            scanf("%d", &a[i]);
            if(a[i] > max_v)
            {
                max_v = a[i];
                max_i = i;
            }
            if(a[i] < min_v)
            {
                min_v = a[i];
                min_i = i;
            }
        }
        if(min_i > max_i)
            swap(min_i, max_i);
        printf("%d %d\n", min_i, max_i);
    }
}
// davidlee1999WTK 2022/
// Team NewType, UT Austin
// srO myk Orz
//ios::sync_with_stdio(false);