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
#define MAX 100050
#define INF 0x3f3f3f3f
#define MOD 1000000007
int main()
{
    int n , x[MAX][2];
    WHILE(n)
    {
        int l = 0 , r = 0;
        REP(i,n) scanf("%d%d",&x[i][0],&x[i][1]) , l+=x[i][0] , r+=x[i][1] ;
        int ans = 0 , now = max(l-r , r-l);
//        cout<<"now = "<<now<<endl;
        REP(i,n)
        {
            int ql = l - x[i][0] + x[i][1];
            int qr = r - x[i][1] + x[i][0];
            int qw = max(ql-qr , qr-ql);
//            cout<<qw<<endl;
            if(qw > now)ans = i+1 , now = qw ;
        }
        printf("%d\n",ans);
    }

    return 0;
}