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
        int n, fr = 0, ls = 0;
        cin >> n;
        int i;
        for(i=1;i<=n;i++)
            scanf("%d", &a[i]);
        for(i=1;i<n;i++)
        {
            if(a[i] == a[i+1])
            {
                if(fr == 0)
                    fr = i;
                ls = i;
            }
        }
        if(ls == 0 || ls == fr)
            cout<< 0 <<endl;
        else if(ls - fr <=1)
            cout << 1 << endl;
        else
            cout << ls - fr - 1 <<endl;
    }
}
// davidlee1999WTK 2022/
// Team NewType, UT Austin
// srO myk Orz
//ios::sync_with_stdio(false);