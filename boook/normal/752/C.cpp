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
#define MAX 20
#define INF 0x3f3f3f3f
#define debug 1

int idx(char q){
    if(q == 'L')return -1;
    if(q == 'R')return -2;
    if(q == 'U')return 1;
    if(q == 'D')return 2;
}
int main(){
    int n;
    string s;
    while(cin >> n >> s){
        int _ = 0 , l = 0;
        int ans = 0;
        REP(i,s.size()){
            int to = idx(s[i]);
            if(to < 0){
                if(_ == 0)_ = to;
                else if(_ != to){
                    ans ++ , _ = to , l = 0;
                }
            }
            else if(to > 0){
                if(l == 0)l = to;
                else if(l != to){
                    ans ++ , _ = 0 , l = to;
                }
            }
        }
        if(_ || l)ans++;
        printf("%d\n",ans);
    }
    return 0;
}