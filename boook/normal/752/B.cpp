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

string s , w;
map<char , char> ma;

int solve(){
    REP(i,s.size()){
        char a = s[i];
        char b = w[i];
        if(a == b){
            if(!ma.count(a))ma[a] = b;
            else if(ma[a]!=b)return -1;
        }
        if(!ma.count(a))ma[a] = b;
        else if(ma[a] != b)return -1;
        if(!ma.count(b))ma[b] = a;
        else if(ma[b] != a)return -1;
    }
    return 0;
}
int main(){
    cin >> s >> w;
    int ans = solve();
    if(ans == -1) printf("%d\n",ans);
    else {
        for(auto i = ma.begin();i != ma.end() ; i++)
            if(i->A > i->B && i->A != i->B)ans++;
        printf("%d\n",ans);
        for(auto i = ma.begin();i != ma.end() ; i++)
            if(i->A > i->B && i->A != i->B)printf("%c %c\n",i->A , i->B);
    }
    return 0;
}