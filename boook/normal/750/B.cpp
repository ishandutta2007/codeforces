#include<bits/stdc++.h>
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
#define MAX 10900
#define INF 0x3f3f3f3f
#define debug 1
#define MOD 100000000000000LL

int main(){

    int n;
    while(cin >> n){
        int ans = 1 , m;
        int now = 0;
        string s;
        REP(i,n){
            cin >> m >> s;
            if(s == "East" || s == "West"){
                if(now == 0 || now ==20000)ans = 0;
            }
            else if(s == "South")now += m;
            else if(s == "North")now -= m;
            if(now < 0 || now > 20000)ans = 0;
        }
        if(now != 0)ans = 0;
        if(ans)puts("YES");
        else puts("NO");
    }
    return 0;
}