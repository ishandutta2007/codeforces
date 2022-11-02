#include<bits/stdc++.h>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef pair<int,int> PII;
typedef long long int LL;
#define REP(i,j)      for(int i=0;i<j;i++)
#define REPNM(i,j,k)  for(int i=j;i<k;i++)
#define RREP(i,j,k)   for(int i=j;i>=k;i--)
#define pb   push_back
#define mp   make_pair
#define A    first
#define B    second
#define MEM(i,j)   memset(i,j,sizeof i)
#define ALL(i)     i.begin(),i.end()
#define DB()          if(debug)
#define DBGG(i,j)     if(debug) cout<<i<<" "<<j<<endl;
#define DB4(i,j,k,l)  if(debug) cout<<i<<" "<<j<<" "<<k<<" "<<l<<endl;
#define RI(i)       scanf("%d",&i)
#define RII(i,j)    scanf("%d%d",&i,&j)
#define RIII(i,j,k) scanf("%d%d%d",&i,&j,&k)
#define RL(i)       scanf("%lld",&i)
#define RLL(i,j)    scanf("%lld%lld",&i,&j)
#define RLLL(i,j,k) scanf("%lld%lld%lld",&i,&j,&k)
///---------------------------
#define MAX 50
#define INF 0x3f3f3f3f
#define debug 1

char p[MAX][MAX];
int main(){

    cin.tie() , cout.sync_with_stdio(0);
    MEM(p , 0);
    REPNM(i,11,15) REPNM(j,11,15){
        cin >> p[i][j];
    }
    int ok = 0;
    REPNM(i,11,15) REPNM(j,11,15){
        if(p[i][j] == '.'){

            if(p[i+2][j] == 'x' && p[i+1][j] == 'x') ok = 1;
            if(p[i-2][j] == 'x' && p[i-1][j] == 'x') ok = 1;
            if(p[i-1][j] == 'x' && p[i+1][j] == 'x') ok = 1;

            if(p[i][j+2] == 'x' && p[i][j+1] == 'x') ok = 1;
            if(p[i][j-2] == 'x' && p[i][j-1] == 'x') ok = 1;
            if(p[i][j-1] == 'x' && p[i][j+1] == 'x') ok = 1;

            if(p[i-1][j-1] == 'x' && p[i-2][j-2] == 'x') ok = 1;
            if(p[i-1][j-1] == 'x' && p[i+1][j+1] == 'x') ok = 1;
            if(p[i+2][j+2] == 'x' && p[i+1][j+1] == 'x') ok = 1;


            if(p[i-2][j+2] == 'x' && p[i-1][j+1] == 'x') ok = 1;
            if(p[i+2][j-2] == 'x' && p[i+1][j-1] == 'x') ok = 1;
            if(p[i-1][j+1] == 'x' && p[i+1][j-1] == 'x') ok = 1;

        }
    }
    if(ok)puts("YES");
    else puts("NO");
    return 0;
}