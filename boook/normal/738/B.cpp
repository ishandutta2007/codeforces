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
#define RI(i) scanf("%d",&i)

/// ----------- default code ----------------
#define MAX 1050
#define INF 0x3f3f3f3f
int n,m , p[MAX][MAX];
int ans;
void F(int y){
    int sum = 0 , res = 0 , L = 0 , R = 0 , good = 0;
    REP(i,m){
        if(p[y][i] == 1) good = 1;
        if(good && p[y][i] == 0) R++;
        if(p[y][i] == 0) res++;
        if(p[y][i] == 1) L = max(L , res);
    }
    sum = L + R;
    ans += sum;
}
void G(int y){
    int sum = 0 , res = 0 , L = 0 , R = 0 , good = 0;
    REP(i,n){
        if(p[i][y] == 1) good = 1;
        if(good && p[i][y] == 0) R++;
        if(p[i][y] == 0) res++;
        if(p[i][y] == 1) L = max(L , res);
    }
    sum = L + R;
    ans += sum;
}
int main()
{

    WHILENM(n,m){
        REP(i,n) REP(j,m) RI(p[i][j]);
        ans = 0;
        REP(i,n)F(i);
        REP(i,m)G(i);
        printf("%d\n",ans);
    }
    return 0;
}