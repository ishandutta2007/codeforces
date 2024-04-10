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
int b[N], cnt[N];
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        int i, j, flag = 1;
        for(i=1;i<=n;i++)
        {
            scanf("%d", &a[i]);
            cnt[i] = 0;
        }
        for(i=1;i<=n;i++)
            scanf("%d", &b[i]);
        for(i=n, j = n; j> 0;)
        {
            //debug(i);
            //debug(j);
            if(a[i] != b[j])
            {
                if(cnt[a[i]])
                {
                    cnt[a[i]]--;
                    i--;
                }
                else
                {
                    flag = 0;
                    break;
                }
            }
            else
            {
                while(b[j-1] == b[j])
                {
                    cnt[b[j]]++;
                    j--;
                }
                i--;
                j--;
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