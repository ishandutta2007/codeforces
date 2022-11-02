#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long int LL;
typedef pair<int,int> PII;
typedef pair<LL , LL> PLL;
#define REP(i,j)      for(int i = 0 ; i < j ; i++)
#define REPNM(i,j,k)  for(int i = j ; i < k ; i++)
#define RREP(i,j,k)   for(int i = j ; i >=k ; i--)
#define LREP(i,j)      for(LL i = 0 ; i < j ; i++)
#define LREPNM(i,j,k)  for(LL i = j ; i < k ; i++)
#define LRREP(i,j,k)   for(LL i = j ; i >=k ; i--)
#define pb   push_back
#define mp   make_pair
#define A    first
#define B    second
#define MEM(i,j)   memset(i,j,sizeof i)
#define ALL(i)     i.begin(),i.end()
#define DB()          if(debug)
#define DBGG(i,j)     if(debug) cout << i << " " << j << endl;
#define DB4(i,j,k,l)  if(debug) cout << i << " " << j << " " << k << " " << l <<endl;
#define RI(i)       scanf("%d" , &i)
#define RII(i,j)    scanf("%d%d" , &i , &j)
#define RIII(i,j,k) scanf("%d%d%d" , &i , &j , &k)
#define RL(i)       scanf("%lld" , &i)
#define RLL(i,j)    scanf("%lld%lld" , &i , &j)
#define RLLL(i,j,k) scanf("%lld%lld%lld" , &i , &j , &k)
#define AS assert
#define IOS cin.tie() , cout.sync_with_stdio(0);
///------------------------------------------------------------
#define MAX 300000
#define INF 0x3f3f3f3f
#define debug 1

map<string , int> cc;
class djs{
public:
    int x[MAX];
    void init() { REP(i , MAX) x[i] = i; }
    int Find(int now) { return now == x[now] ? now : x[now] = Find(x[now]); }
    void Union(int u , int v) { x[Find(u)] = Find(v); }
    int operator[](const int now) { return Find(now);}
};
djs ds;
int main(){
    int n , m , k;
    string s , g;
    while(cin >> n >> m >> k){
        REPNM(i , 1 , n + 1){
            cin >> s;
            cc[s] = i;
        }
        ds.init();
        int tmp , q , w;
        REP(i , m){
            cin >> tmp >> s >> g;
            q = cc[s] , w = cc[g];
            if(tmp == 1){
                if(ds[w * 2] == ds[q * 2 + 1]) cout << "NO" << endl;
                else{
                    cout << "YES" << endl;
                    ds.Union(ds[w * 2] , ds[q * 2]);
                    ds.Union(ds[w * 2 + 1] , ds[q * 2 + 1]);
                }
            }
            else {
                if(ds[w * 2] == ds[q * 2]) cout << "NO" << endl;
                else {
                    cout << "YES" << endl;
                    ds.Union(ds[w * 2] , ds[q * 2 + 1]);
                    ds.Union(ds[w * 2 + 1] , ds[q * 2]);
                }
            }
        }
        REP(i , k){
            cin >> s >> g;
            q = cc[s] , w = cc[g];
            if(ds[q * 2] == ds[w * 2]) cout << "1" << endl;
            else if(ds[q * 2] == ds[w * 2 + 1]) cout << "2" << endl;
            else cout << "3" << endl;
        }
    }
    return 0;
}