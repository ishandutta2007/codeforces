#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j)       for(int i = 0 ; i < j ; i++)
#define REPNM(i,j,k)   for(int i = j ; i < k ; i++)
#define RREP(i,j,k)    for(int i = j ; i >=k ; i--)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
#define PII pair<int , int>
#define VI  vector<int> 
#define VPII vector<PII>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
///------------------------------------------------------------
#define MAX 100090
#define INF 0x3f3f3f3f
typedef long long int LL;

int n , m , k;
int forest[MAX] , dis[MAX] , trlen[MAX];
VI v[MAX] , tr[MAX];

PII DFS1(int now , int fa , int root){
    forest[now] = root;
    PII ans = mp(0 , now);
    for(auto to : v[now]){
        if(to == fa) continue;
        PII tmp = DFS1(to , now , root);
        if(tmp.A + 1 > ans.A) ans = mp(tmp.A + 1 , tmp.B);
    }
    return ans;
}
void DFS2(int now , int fa , int deep){
    dis[now] = max(dis[now] , deep);
    for(auto to : v[now]){
        if(to == fa) continue;
        DFS2(to , now , deep + 1);
    }
}
vector<LL> d[MAX] , pre[MAX];
void solveinit(){
    REPNM(i , 1 , n + 1){
        PII a , b;
        if(forest[i] == 0){
            a = DFS1(i , 0 , i);
            b = DFS1(a.B , 0 , i);
            DFS2(a.B , 0 , 0) , DFS2(b.B , 0 , 0);
            trlen[i] = b.A;
        }
    }
    REPNM(i , 1 , n + 1) tr[forest[i]].pb(i);

    REPNM(i , 1 , n + 1){
        for(auto j : tr[i]) d[i].pb(dis[j]);
        sort(ALL(d[i]));
        if(d[i].size()){
            pre[i].pb(d[i][0]);
            REPNM(j , 1 , d[i].size())
                pre[i].pb(pre[i][j - 1] + d[i][j]);
        }
    }
}
map<PII , pair<LL , LL> > cc;
void solve(int a , int b){
    LL len = 0 , all = LL(tr[a].size()) * LL(tr[b].size());
    LL lim = max(trlen[a] , trlen[b]);
    for(auto now : tr[a]){
        if(dis[now] + d[b][0] + 1 > lim){
            len += pre[b].back() + tr[b].size() * (dis[now] + 1);
        }
        else {
            int nw = 0;
            RREP(j , 20 , 0){
                int to = nw + (1 << j);
                if(to < tr[b].size() && dis[now] + d[b][to] + 1 < lim)
                    nw = to;
            }
            len += (nw + 1) * lim;
            len += (LL(tr[b].size()) - (nw + 1)) * (dis[now] + 1) 
                + pre[b].back() - pre[b][nw];
        }
    }
    cc[mp(a , b)] = mp(len , all);
    double ans = double(cc[mp(a , b)].A) / double(cc[mp(a , b)].B);
    printf("%0.9f\n", ans);
}
int32_t main(){
    int q , w;
    scanf("%d%d%d" , &n , &m , &k);
    REPNM(i , 1 , m + 1){
        scanf("%d%d" , &q , &w);
        v[q].pb(w) , v[w].pb(q);
    }
    solveinit();
    REPNM(i , 1 , k + 1){
        scanf("%d%d" , &q , &w);
        q = forest[q] , w = forest[w];
        if(tr[q].size() > tr[w].size()) swap(q , w);
        if(q == w) puts("-1");
        else{
            if(cc.find(mp(q , w)) != cc.end()){
                double ans = double(cc[mp(q , w)].A) / double(cc[mp(q , w)].B);
                printf("%0.9f\n", ans);
            }
            else solve(forest[q] , forest[w]);
        }
    }
    return 0;
}