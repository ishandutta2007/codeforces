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
vector<vector<int> > a, b;
bool vis[N];
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n, m;
        cin >> n >> m;
        //debug(n);
        //debug(m);
        int i, j;
        a.clear();
        a.resize(n);
        memset(vis, 0, sizeof(vis));
        for(i=0;i<n;i++)
        {
            a[i].resize(m);
            for(j=0;j<m;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        b = a;
        for(i=0;i<n;i++)
            sort(b[i].begin(), b[i].end());
        vector<int> rel;
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                if(a[i][j] !=  b[i][j])
                {
                    vis[j] = 1;
                }

        //debug(a.size());
        //debug(a[0].size());
        int flag = 0;
        for(j=0;j<m;j++)
        {
            if(vis[j])
            {
                flag++;
                rel.push_back(j);
            }
        }
        //debug(flag);
        //debug("output here");
        if(flag == 0)
            printf("1 1\n");
        else if(flag == 2)
        {
            int ok = 1;
            //debug(rel[0]);
            //debug(rel[1]);
            for(i=0;i<n;i++)
                swap(a[i][rel[0]], a[i][rel[1]]);
            for(i=0;i<n;i++)
            {
                for(j=0;j<m;j++)
                    if(j >= 1 && a[i][j] < a[i][j-1])
                        ok = 0;
            }
            if(ok)
                printf("%d %d\n", rel[0]+1, rel[1]+1);
            else
                printf("-1\n");
        }
        else
            cout<<-1<<endl;
    }
    return 0;
}
// davidlee1999WTK 2022/
// Team NewType, UT Austin
// srO myk Orz
//ios::sync_with_stdio(false);