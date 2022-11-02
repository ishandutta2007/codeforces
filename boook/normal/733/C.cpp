#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
typedef long long LL;
#define REP(i,j) for(int i=0;i<j;i++)
#define REPNM(i,j,k) for(int i=j;i<k;i++)
#define WHILE(n) while(scanf("%d",&n)==1)
#define WHILE_(n) while(scanf("%d",&n)==1 && n)
#define WHILENM(n,m) while(scanf("%d%d",&n,&m)==2)
#define WHILENM_(n,m) while(scanf("%d%d",&n,&m)==2 && n && m)
#define INf 0x3f3f3f3f
#define MEM(i,j) memset(i,j,sizeof i)
#define a first
#define b second
#define pb push_back
#define mp make_pair

/// --------default_code----------
#define MAX 510
#define INF 0x3f3f3f3f
#define MOD 1000000007
int n , x[MAX] , g , goal[MAX] ;
int q[MAX][2];
vector<PII> ans;
int F(int from , int to , int ba)
{
//    cout<<"from = "<<from <<"  to  = "<<to<<endl;
    int num = to - from + 1 , first = from , mm = 0;
    if(num == 1)return 0;
    REPNM(i,from,to+1)
        mm = max(mm , x[i]);
    int start = -1;
    REPNM(i,from,to+1)
    {
//        printf("i  = %d\n",i);
        int fpo = i-1 , bpo = i+1 , qc = x[i];
        while(1)
        {
            int can = 1;
            while(fpo>=from && qc>x[fpo]) qc+=x[fpo] , fpo-- , can = 0;
            while( bpo<=to  && qc>x[bpo]) qc+=x[bpo] , bpo++ , can = 0;
            if(qc > mm)start = i;
            if(can)break;
        }
        if(start != -1)break;
    }
//    cout<<"start\t"<<start<<endl;
    if(start == -1)return -1;
    int now = start-from+ba;
    int fpo = start-1 , bpo = start+1 , qc = x[start];
    while(num--)
    {

        if(fpo>=from && qc>x[fpo]) qc+=x[fpo] , fpo-- , ans.pb(mp(now,0)) , now--;
        else if( bpo<=to  && qc>x[bpo]) qc+=x[bpo] , bpo++ , ans.pb(mp(now,1));
//        cout<<"\t\t"<<qc<<endl;
    }
    return 0;
}
int main()
{

    WHILE(n)
    {
        ans.clear();
        REP(i,n) scanf("%d",&x[i]);
        scanf("%d",&g);
        REP(i,g) scanf("%d",&goal[i]);
        int po = 0 , add = 0 , ifans = 1 , from =0;
        REP(i,n)
        {
            add += x[i] ;
            if(add == goal[po])
            {
                if(F(from,i,po) == -1){ ifans = false ; break ; }
                po++ , add = 0 , from = i+1;
            }
            else if(add > goal[po])
            {
                ifans = 0;
                break;
            }
        }
        if( po != g ) ifans = false;
        if(ifans)
        {
            puts("YES");
            REP(i,ans.size())
                if(ans[i].b==0)printf("%d L\n",ans[i].a+1);
                else printf("%d R\n",ans[i].a+1);
        }
        else puts("NO");
    }

    return 0;
}