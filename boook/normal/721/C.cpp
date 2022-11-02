#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
typedef pair<int,int> PII;
#define REP(i,j) for(int i=0;i<j;i++)
#define REPNM(i,j,k) for(int i=j;i<k;i++)
#define WHILE(n) while(scanf("%d",&n)==1)
#define WHILE_(n) while(scanf("%d",&n)==1 && n)
#define WHILENM(n) while(scanf("%d%d",&n,&m)==2)
#define WHILENM_(n) while(scanf("%d%d",&n,&n,&m)==2 && n && )
#define MEM(i,j) memset(i,j,sizeof i)
#define mp(i,j) make_pair(i,j)
#define a first
#define b second
#define MAX 5010
#define INF 0x3f3f3f3f
class Dijsta
{
public:
    int d[MAX][MAX] , pa[MAX][MAX];
    vector<PII> v[MAX];
    void C(int s,int tt,int k)
    {
        /// d times dot
        typedef pair<int,pair<int,int> > PIII;
        priority_queue<PIII,vector<PIII>,greater<PIII> > pq;
        MEM(d,INF) , d[s][1]=0 ;
        pq.push( mp(0,mp(1,s)) );
        int ans = 0;
        while(pq.size())
        {
            PIII now = pq.top() ; pq.pop();
            if( d[now.b.b][now.b.a] > now.a )continue;
            REP(i,v[now.b.b].size())
            {
                PII to = v[now.b.b][i];
                if( d[to.a][now.b.a+1] > now.a + to.b)
                {
                    d[to.a][now.b.a+1] = now.a + to.b;
                    pa[to.a][now.b.a+1] = now.b.b;
                    pq.push( mp( d[to.a][now.b.a+1] ,mp( now.b.a+1 , to.a ) ) );
                }
            }
        }
//        cout<<"here"<<endl;
        vector<int> aa;
        for(int i=tt;i>=0;i--)
        {
            if(d[tt][i]<=k)
            {
                int ii=i;
                for(int j=tt ; j!=1 ; j = pa[j][ii] , ii--)
                {
                    aa.push_back(j);
//                    cout<<j<<endl;
                }
                break;
            }
        }
        printf("%d\n%d",aa.size()+1,1);
        for(int i=aa.size()-1;i>=0;i--)
            printf(" %d",aa[i]);puts("");
    }
};
Dijsta dj;
int main()
{
    int n,m,k;
    while(scanf("%d%d%d",&n,&m,&k)==3)
    {
        int q , w ,e;
        REP(i,m)
        {
            scanf("%d%d%d",&q,&w,&e);
            dj.v[q].push_back(mp( w, e ));
        }
        dj.C(1,n,k);
    }
    return 0;
}