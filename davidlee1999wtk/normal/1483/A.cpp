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
int ans[N];
vector<int> fri[N];
int cnt[N];
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,m,k,i,j, f_num,flag=1;
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
            cnt[i]=0;
        for(i=1;i<=m;i++)
        {
            fri[i].clear();
            ans[i]=0;
            scanf("%d",&k);
            for(j=1;j<=k;j++)
            {
                scanf("%d",&f_num);
                fri[i].push_back(f_num);
            }
            if(k==1)
            {
                ans[i]=fri[i][0], cnt[fri[i][0]]++;
                if(cnt[fri[i][0]]>(m+1)/2)
                    flag=0;
            }
        }
        for(i=1;i<=m;i++)
        {
            if(ans[i]==0)
            {
                for(j=0;j<fri[i].size();j++)
                {
                    if(cnt[fri[i][j]]<(m+1)/2)
                    {
                        ans[i]=fri[i][j];
                        cnt[fri[i][j]]++;
                        break;
                    }
                }
                if(j==fri[i].size())
                    flag=0;
            }
        }
        if(flag==1)
        {
            printf("YES\n");
            for(i=1;i<=m;i++)
                printf("%d ", ans[i]);
            printf("\n");
        }
        else
            printf("NO\n");
    }
    return 0;
}
// davidlee1999WTK 2021/
// srO myk Orz
//ios::sync_with_stdio(false);