#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int , int> PII;
#define REP(i,j) for(int i=0;i<j;i++)
#define REPNM(i,j,k) for(int i=j;i<k;i++)
#define RREP(i,j,k) for(int i=j;i>=k;i--)
#define MEM(i,j) memset(i,j,sizeof i)
#define WHILE(n) while(~scanf("%d",&n))
#define WHILE_(n) while(~scanf("%d",&n) && n)
#define WHILENM(n,m) while(~scanf("%d%d",&n,&m))
#define WHILENM_(n,m) while(~scanf("%d%d",&n,&m) && (n || m) )
#define pb push_back
#define mp make_pair
#define A first
#define B second
#define AC 53LL
#define AMOD 1000000079LL
#define debug 0
#define DB() if(debug)

/// ----------- default code ----------------
#define MAX 10
#define INF 0x3f3f3f3f

LL a,b,c,d;

int main()
{
    while(cin>>a>>b>>c>>d){
        LL ans = 0;
        LL mm = min(a,min(c,d));
        ans += mm * 256;
        a -= mm;
        c -= mm;
        d -= mm;
        mm = min(a,b);
        ans += mm * 32;
        cout<<ans<<endl;
    }
    return 0;
}