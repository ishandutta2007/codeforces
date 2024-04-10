#include <bits/stdc++.h>
using namespace std;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define MEM(i,j)   memset(i , j , sizeof i)
#define pb push_back
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
#define MAX 550

struct {
    int x[MAX * MAX] , siz[MAX * MAX];
    void init(){ REP(i , 0 , MAX * MAX) x[i] = i , siz[i] = 1; }
    int Find(int now){ return x[now] == now ? now : x[now] = Find(x[now]); }
    void Union(int a , int b){
        a = Find(a) , b = Find(b);
        if(a != b) x[b] = a , siz[a] += siz[b];
    }
    int operator[](int now){ return Find(now); }
} ds;
int n , m , sum[MAX][MAX];
string s[MAX];
int IN(int a , int b){
    return a >= 0 && a < n && b >= 0 && b < n && s[a][b] == '.';
}
int id[MAX][MAX] , po = 1 , cnt[MAX * MAX] , use[MAX * MAX];
int32_t main(){
    ds.init();
    IOS , cin >> n >> m;
    REP(i , 0 , n) cin >> s[i];

    REP(i , 0 , n) REP(j , 0 , n)  id[i][j] = po ++;
    REP(i , 1 , n) REP(j , 0 , n) if(s[i][j] == '.' && s[i - 1][j] == '.') ds.Union(id[i][j] , id[i - 1][j]);
    REP(i , 0 , n) REP(j , 1 , n) if(s[i][j] == '.' && s[i][j - 1] == '.') ds.Union(id[i][j] , id[i][j - 1]);

    REP(i , 0 , n){
        if(i + m - 1 >= n) break;
        MEM(cnt , 0);

        int fr = 0 , ba = m - 1;
        REP(ii , i , i + m){
            REP(jj , 0 , m - 1){
                if(s[ii][jj] == '.') cnt[ds[id[ii][jj]]] ++;
            }
        }
        while(ba < n){
            REP(ii , i , i + m)
                if(s[ii][ba] == '.') cnt[ds[id[ii][ba]]] ++;

            vector<int> sol;
            REP(jj , fr , ba + 1) if(IN(i - 1 , jj)) sol.pb(id[i - 1][jj]);
            REP(jj , fr , ba + 1) if(IN(i + m , jj)) sol.pb(id[i + m][jj]);
            REP(ii , i , i + m) if(IN(ii , fr - 1)) sol.pb(id[ii][fr - 1]);
            REP(ii , i , i + m) if(IN(ii , ba + 1)) sol.pb(id[ii][ba + 1]);

            int tmp = m * m;
            for(auto to : sol){
                int now = ds[to];
                if(use[now] == 0) use[now] = 1 , tmp += ds.siz[now] - cnt[now];
            }
            for(auto to : sol) use[ds[to]] = 0;
            sum[i][fr] = tmp;
            REP(ii , i , i + m)
                if(s[ii][fr] == '.') cnt[ds[id[ii][fr]]] --;
            fr ++ , ba ++;
        }
    }
    int ans = 0;
    REP(i , 0 , n) REP(j , 0 , n) ans = max(ans , sum[i][j]);
    cout << ans << endl;
    return 0;
}