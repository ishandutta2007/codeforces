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
#define MAX 300900
#define INF 0x3f3f3f3f

int n , m , col[MAX];
PII x[MAX];
VI o[MAX] , p[MAX];
set<PII> use;
class djs{
public:
    int x[MAX];
    void init(){ REP(i , MAX) x[i] = i; }
    int Find(int now){ return now == x[now] ? now : x[now] = Find(x[now]); }
    void Union(int a , int b){ x[Find(a)] = Find(b); }
    int operator[](int now){ return Find(now); }
}ds;
PII TR(PII now){ return mp(max(now.A , now.B) , min(now.A , now.B)); }
int ok;
int DFS(int now , int fa , int nowcol){
    col[now] = nowcol;
    int cnt = 0;
    for(auto to : p[now]){
        if(to != fa) cnt ++;
    }
    if(cnt > 1) ok = 0;
    for(auto to : p[now]){
        if(to != fa) DFS(to , now , nowcol + 1);
    }
}
int32_t main(){
    ds.init();
    cin >> n >> m;
    REPNM(i , 1 , m + 1){
        cin >> x[i].A >> x[i].B;
        o[x[i].A].pb(x[i].B);
        o[x[i].B].pb(x[i].A);
    }
    REPNM(i , 1 , n + 1)
        o[i].pb(i) , sort(ALL(o[i]));
    REPNM(i , 1 , m + 1){
        if(o[x[i].A] == o[x[i].B]){
            ds.Union(x[i].A , x[i].B);
        }
    }
    int qqq = 1;
    REPNM(i , 1 , m + 1){
        if(ds[x[i].A] != ds[x[i].B]){
            qqq = 0;
            PII tmp = TR(mp(ds[x[i].A] , ds[x[i].B]));
            if(use.find(tmp) == use.end()){
                use.insert(tmp);
                p[tmp.A].pb(tmp.B);
                p[tmp.B].pb(tmp.A);
                // DBGG(tmp.A , tmp.B);
            }
        }
    }
    if(qqq){
        puts("YES");
        REPNM(i , 1 , n + 1){
            cout << "1 "; 
        }
        return puts("");
    }
    int tmp = 0;
    REPNM(i , 1 , n + 1){
        if(p[i].size() == 1 && tmp == 0) tmp = i;
        if(p[i].size() > 2) tmp = -1;
    }
    if(tmp <= 0) puts("NO");
    else {
        ok = 1 , DFS(tmp , 0 , 1);
        if(ok != 1) return puts("NO");
        else {
            puts("YES");
            REPNM(i , 1 , n + 1){
                cout << col[ds[i]] << " ";
            }
            puts("");
        }
    }
    return 0;
}