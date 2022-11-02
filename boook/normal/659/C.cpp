#include<bits/stdc++.h>
using namespace std;
#define REP(i,j) for(int i=0;i<j;i++)
#define REPNM(i,j,k) for(int i=j;i<k;i++)
#define MEM(i,j) memset(i,j,sizeof i)
#define WHILE(n) while(scanf("%d",&n)==1)
#define WHILE_(n) while(scanf("%d",&n)==1 && n)
#define WHILENM(n,m) while(scanf("%d%d",&n,&m)==2)
#define WHILENM_(n,m) while(scanf("%d%d",&n,&m)==2 && n && m)
#define mp(n,m) make_pair(n,m)
#define pb(n) push_back(n)
#define a first
#define b second
#define INF 0x3f3f3f3f
#define MAX 50000
int main()
{
    int n,m;
    WHILENM(n,m)
    {
        unordered_set<int> st;
        int q;
        REP(i,n) scanf("%d",&q) , st.insert(q);
        vector<int> ans;
        int po = 1 ;
        while(1)
        {
            while(st.count(po))po++;
            if(m<po)break;
            ans.push_back(po);
            m-=po;po++;
        }
        printf("%d\n",ans.size());
        if(ans.size() )printf("%d",ans[0]);
        REPNM(i,1,ans.size())
            printf(" %d",ans[i]);puts("");



    }

    return 0;
}