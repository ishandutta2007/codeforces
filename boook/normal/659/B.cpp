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
typedef pair<int,string> PIS;
#define MAX 50000
vector<PIS> v[MAX];
int main()
{
    int n,m;
    WHILENM(n,m)
    {
        REP(i,m+1)v[i].clear();
        REP(i,n)
        {
            PIS w;
            int q;
            cin>>w.b>>q>>w.a;
            v[q].pb(w);
        }
        REPNM(i,1,m+1)
        {
//            cout<<endl<<i<<endl;
            sort(v[i].begin(),v[i].end(),greater<PIS>());
            if(v[i].size() < 2) printf("?\n");
            else if(v[i].size() >= 3)
            {
                if(v[i][1].a == v[i][2].a)printf("?\n");
                else cout <<v[i][0].b<<" "<<v[i][1].b<<endl;
            }
            else cout <<v[i][0].b<<" "<<v[i][1].b<<endl;
        }
    }

    return 0;
}