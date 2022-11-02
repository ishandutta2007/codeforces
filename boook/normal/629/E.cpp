#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define mp   make_pair
#define pb   emplace_back
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 100900
#define INF 0x3f3f3f3f

int n , m;
int in[MAX] , out[MAX] , po = 1 , sp[MAX][20];
int siz[MAX] , dep[MAX] , sum[MAX] , all[MAX];
vector<int> v[MAX];
void DFS1(int now , int fa , int deep){
    in[now] = po ++;
    siz[now] = 1;
    dep[now] = deep;
    sp[now][0] = fa;
    for(auto to : v[now]){
        if(to == fa) continue;
        DFS1(to , now , deep + 1);
        siz[now] += siz[to];
        sum[now] += sum[to] + siz[to];
    }
    out[now] = po ++;
}
void DFS2(int now , int fa){
    for(auto to : v[now]){
        if(to == fa) continue;
        all[to] = all[now] - siz[to] + (n - siz[to]);
        DFS2(to , now);
    }
}
int isfa(int fa , int now){
    // DB4("isfa = " , fa , now , (in[fa] <= in[now] && out[fa] >= out[now]));
    return (in[fa] <= in[now] && out[fa] >= out[now]);
}
int LCA(int a , int b){
    if(isfa(a , b)) return a;
    RREP(i , 19 , 0){
        if(isfa(sp[a][i] , b) == 0) a = sp[a][i];
    }
    return sp[a][0];
}
int DIS(int a , int b){
    // DBGG("LCA = " , LCA(a , b));
    return dep[a] + dep[b] - dep[LCA(a , b)] * 2;
}
void query(int a , int b){
    int ans = 0 , sz , res , dis = DIS(a , b) + 1;

    if(dep[a] > dep[b]) swap(a , b);
    
    if(isfa(a , b)){
        int dd = b;
        RREP(i , 19 , 0){
            if(sp[dd][i] != a && isfa(a , sp[dd][i])) dd = sp[dd][i];
        }
        assert(sp[dd][0] == a);
        res = all[a] - sum[dd] - siz[dd];
        sz = n - siz[dd];
    }
    else {
        sz = siz[a];
        res = sum[a];
    }
    // DB4("a = " , a , sz , res);
    ans += dis * sz * siz[b];
    ans += res * siz[b];
    ans += sum[b] * sz;
    double tt = sz * siz[b];
    // DB4("ans = " , ans , "tt = " , tt);
    // DBGG("dis = " , dis);
    printf("%.011f\n", (double)ans / tt);
}
void solveinit(){
    DFS1(1 , 0 , 0);
    all[1] = sum[1]; out[0] = INF;
    DFS2(1 , 0);
    REP(j , 1 , 20) REP(i , 0 , n + 1) sp[i][j] = sp[sp[i][j - 1]][j - 1];
    // cout << "in[] = " ;
    // REP(i , 1 , n + 1) cout << in[i] << " " ; cout << endl;
    // cout << "out[] = ";
    // REP(i , 1 , n + 1) cout << out[i] << " " ; cout << endl;
    // cout << "siz[] = ";
    // REP(i , 1 , n + 1) cout << siz[i] << " " ; cout << endl;
    // cout << "dep[] = ";
    // REP(i , 1 , n + 1) cout << dep[i] << " " ; cout << endl;
    // cout << "sum[] = " ;
    // REP(i , 1 , n + 1) cout << sum[i] << " " ; cout << endl;
    // cout << "pre[] = " ;
    // REP(i , 1 , n + 1) cout << all[i] << " " ; cout << endl;
}
int32_t main(){
    cin >> n >> m;
    REP(i , 1 , n){
        int q , w;
        cin >> q >> w;
        v[q].pb(w);
        v[w].pb(q);
    }
    solveinit();
    REP(i , 1 , m + 1){
        int q , w;
        cin >> q >> w;
        query(q , w);
    }
    return 0;
}