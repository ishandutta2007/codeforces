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
    int T, i;
    cin >> T;
    while(T--)
    {
        int n;
        int flag = 0;
        cin >> n;
        for(i=1;i<=n;i++)
        {
            scanf("%d", &a[i]);
            if(a[i] == 1)
                flag = 1;
        }
        if(flag == 0)
        {
            cout<<"YES"<<endl;
            continue;
        }
        sort(a+1, a+1+n);
        for(i=1;i<n;i++)
        {
            if(a[i+1] - a[i] == 1)
                flag = 0;
        }
        if(flag == 0)
        {
            cout<<"NO"<<endl;
            continue;
        }
        else
            cout<<"YES"<<endl;
    }
}
// davidlee1999WTK 2022/
// Team NewType, UT Austin
// srO myk Orz
//ios::sync_with_stdio(false);