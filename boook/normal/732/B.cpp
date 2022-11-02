#include<bits/stdc++.h>
#include<ext/pb_ds/priority_queue.hpp>
using namespace std;
typedef pair<int,int> PII;
#define REP(x,y) for(int x=0;x<y;x++)
#define REPNM(x,y,z) for(int x=y;x<z;x++)
#define MEM(x,y) memset(x,y,sizeof x)
#define WHILE(n) while(scanf("%d",&n)==1)
#define WHILE_(n) while(scanf("%d",&n)==1 && n)
#define WHILENM(n,m) while(scanf("%d%d",&n,&m)==2)
#define mp(n,m) make_pair(n,m)
#define AC 37
#define BC 41
#define AMOD 100000017
#define BMOD 100000029
#define a first
#define b second

#define MAX 1000
#define INF 0x3f3f3f3f
//__gnu_pbds::priority_queue<PSI> pq;





int main()
{
    int n,m ,x[MAX];
    WHILENM(n,m)
    {
        REP(i,n)scanf("%d",&x[i]);
        int ans = 0;
        REPNM(i,1,n)
        {
            if(x[i-1]+x[i]<m)ans += m-x[i-1] - x[i] , x[i] = m-x[i-1];
        }
        printf("%d\n%d",ans,x[0]);
        REPNM(i,1,n)printf(" %d",x[i]);puts("");
    }
    return 0;
}
class DisSet
{
    public : int x[MAX];
    DisSet()
    { REP(i,MAX) x[i] = i; }
    int F(int a){ return a==x[a] ? a : x[a] = F(x[a]); }
    void U(int a,int b){ x[F(a)] = F(b); }
};
class DijTra
{
    public :
    vector<PII> v[MAX];
    int d[MAX],pa[MAX];
    void C(int s)
    {
        priority_queue< PII , vector<PII> , greater<PII> > pq;
        fill(d,d+MAX,INF) , d[s] = 0;
        pq.push(mp(s,0));
        while(pq.size())
        {
            PII now = pq.top(); pq.pop();
            if( now.b > d[now.a]) continue;
            REP(i,v[now.a].size())
            {
                PII to = v[now.a][i];
                if( d[to.a] > now.b + to.b )
                {
                    d[to.a] = now.b + to.b;
                    pa[to.a] = now.a;
                    pq.push( mp(to.a , d[to.a]) );
                }
            }
        }
    }
};
class KMP
{
public:
    string s;
    int f[MAX];
    void C()
    {
        int q;
        q = f[0] = -1 ;
        REPNM(i,1,s.length())
        {
            while( q!=-1 && s[q+1]!=s[i] ) q = f[q];
            if(s[q+1]==s[i])q++;
            f[i] = q;
        }
    }
};
class Kruskal
{
    typedef pair< int ,PII > PIP;
    DisSet d;
    vector< PIP > v;
    int C()
    {
        int ans = 0;
        sort(v.begin() , v.end());
        REP(i,v.size())
        {
            PII now = v[i].b;
            if(d.F(now.a) != d.F(now.b))
            {
                ans += v[i].a;
                d.U(now.a,now.b);
            }
        }
        return ans;
    }
};
class Zvalue
{
public:
    string s;
    int z[MAX];
    void C()
    {
        int L = 0 , R = 0; z[0] = 0 ;
        REPNM(i,1,s.length())
        {
            if(i > R)z[i] = 0;
            else
            {
                int q = i - L;
                if( q + z[q] < z[L])z[i] = z[q];
                else z[i] = R - i + 1;
            }
            while(i + z[i] < s.length() && s[i+z[i]] == s[z[i]]  ) z[i] ++ ;
            if(i + z[i] -1 > R) L = i ,R = i+z[i] -1;
        }

    }
};