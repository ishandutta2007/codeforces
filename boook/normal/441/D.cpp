#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long int LL;
typedef pair<int,int> PII;
typedef pair<LL , LL> PLL;
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
#define AS assert
///------------------------------------------------------------
#define MAX 4000
#define INF 0x3f3f3f3f
#define debug 1

int n , wnt , po;
int x[MAX] , use[MAX];
int id[MAX] , v[MAX];
vector<int> g[MAX * 10];

vector<PII> Ans;
void DFS(int now){
    if(use[now]) return ;
    g[po].pb(now);
    use[now] = 1;
    id[now] = po;
    DFS(v[now]);
}
// int GETPRE(int now , int ww){
//     if(v[now] == ww)return now;
//     else return GETPRE(v[now] , ww);
// }
int main(){

    RI(n);
    REPNM(i , 1 , n + 1) RI(x[i]);
    RI(wnt);

    REPNM(i , 1 , n + 1){
        v[i] = x[i];
    }

    po = 0;
    REPNM(i , 1 , n + 1) if(use[i] == 0) po ++ , DFS(i);
    int now = n - po;

    int ans = abs(wnt - now);
    printf("%d\n", ans);
    if(wnt > now){
        REP(i , wnt - now){ //add
            int ttmp = id[1];
            REPNM(j , 1 , n + 1){
                if(id[j] != ttmp){
                    int FK = id[j];
                    REPNM(k , 1 , n + 1){
                        if(id[k] == FK) id[k] = ttmp;
                    }
                    Ans.pb(mp(j , 1));
                    break;
                }
            }
        }
    }
    else {
        REP(i , now - wnt){
            REPNM(j , 1 , n + 1){
                if(g[id[j]].size() != 1){
                    int a = INF , b = INF;
                    REPNM(k , 1 , n + 1){
                        if(id[j] == id[k]){
                            int ta = a , tb = b , tc = k;
                            if(ta < tb && ta < tc)a = ta , b = min(tb , tc);
                            else if(tb < ta && tb < tc)a = tb , b = min(ta , tc);
                            else if(tc < ta && tc < tb)a = tc , b = min(ta , tb);
                        }
                    }
                    int QQ = v[b] , WW = v[a];
                    v[b] = WW;
                    v[a] = QQ;

                    // int prea = GETPRE(a , a);
                    // int preb = GETPRE(b , b);
                    
                    // v[prea] = b;
                    // v[preb] = a;
                    g[id[b]].clear();
                    MEM(use , 0);
                    po++;
                    DFS(a);

                    MEM(use , 0);
                    po++;
                    DFS(b);
                    Ans.pb(mp(a , b));
                    // if(n == 456 && min(a , b) == 9 && max(a , b) == 27) cout << endl << g[id[9]].size() << "??" << endl;
                    break;
                }
            }
        }
    }
    REP(i , Ans.size()) if(Ans[i].A > Ans[i].B) swap(Ans[i].A , Ans[i].B);
    sort(ALL(Ans));
    REP(i , Ans.size()) printf("%d %d ", Ans[i].A , Ans[i].B);
    puts("");
    return 0;
}