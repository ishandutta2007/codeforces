/*input
3 3
1 1
2 2
3 3
0 10
1 9
2 8
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
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
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 300900
#define INF 0x3f3f3f3f
#define mod 1000000123LL
int AC;
PII operator + (PII x , PII y){ return mp(x.A + y.A , x.B + y.B); }
PII operator - (PII x , PII y){ return mp(x.A - y.A , x.B - y.B); }
PII operator * (PII x , PII y){ return mp(x.A * y.A , x.B * y.B); }
int cross(PII x , PII y){
    int val = x.A * y.B - x.B * y.A;
    return (val > 0) - (val < 0);
    return val;
}

struct CovexHull{
    int n;
    PII x[MAX];
    int check(PII a , PII b , PII c){
        int val = cross(b - a , c - a);
        return (val > 0) - (val < 0);
    }
    vector<PII> solve(){
        sort(x + 1 , x + 1 + n);
        vector<PII> fr , ba;
        REP(i , 1 , n + 1){
            while(fr.size() >= 2 && check(fr[fr.size() - 2] , fr[fr.size() - 1] , x[i]) != -1)
                fr.pop_back();
            fr.pb(x[i]);
        }
        RREP(i , n , 1){
            while(ba.size() >= 2 && check(ba[ba.size() - 2] , ba[ba.size() - 1] , x[i]) != -1)
                ba.pop_back();
            ba.pb(x[i]);
        }
        REP(i , 1 , ba.size()) fr.pb(ba[i]);
        return fr;
    }
    int CalcArea(vector<PII> sol){
        int ans = 0;
        REP(i , 1 , sol.size()){
            PII a = sol[i - 1] , b = sol[i];
            ans += a.A * b.B - a.B * b.A;
        }
        return abs(ans);
    }
} x , y;
struct {
    int x[MAX] , h[MAX];
    void solveinit(vector<int> s){
        h[0] = 1 , x[0] = 0;
        REP(i , 1 , s.size() + 1) {
            h[i] = (h[i - 1] * AC) % mod;
            x[i] = (x[i - 1] * AC + s[i - 1]) % mod;
        }
    }
    inline int query(int l , int r){ // 1 base !!! [l , r]
        if(l > r) return 0;
        else {
            int v1 = x[r] , v2 = x[l - 1] * h[r - l + 1] % mod;
            return (v1 + mod - v2) % mod;
        }
    }
} sovler;


int S(PII now){
    int a = abs(now.A) % mod , b = abs(now.B) % mod;
    return (a * a + b * b) % mod;
}


vector<PII> v1 , v2;
int solve(){
    PII sum = mp(0 , 0) , mid = mp(0 , 0);
    REP(i , 0 , v1.size()) v1[i] = v1[i] * mp(v1.size() , v1.size());
    REP(i , 0 , v2.size()) v2[i] = v2[i] * mp(v2.size() , v2.size());

    sum = mp(0 , 0);
    REP(i , 0 , v1.size()) sum = sum + v1[i];
    mid = mp(sum.A / v1.size() , sum.B / v1.size());

    int hashval = 0 , cnt = 0;
    REP(i , 0 , v1.size()){
        int j = (i + 1) % v1.size();
        // DB4((v1[i] - v1[j]).A , (v1[i] - v1[j]).B , (v1[i] - mid).A , ((v1[i] - mid)).B);
        int edge = S(v1[i] - v1[j]) ^ S(v1[i] - mid);
        // DBGG("edge = " , edge);
        hashval = (hashval * AC + edge) % mod;
    }

    sum = mp(0 , 0);
    REP(i , 0 , v2.size()) sum = sum + v2[i];
    mid = mp(sum.A / v2.size() , sum.B / v2.size());
    // cout << "--------------" << endl;
    vector<int> tmp;
    REP(i , 0 , v2.size()){
        int j = (i + 1) % v2.size();
        // DB4((v2[i] - v2[j]).A , (v2[i] - v2[j]).B , (v2[i] - mid).A , ((v2[i] - mid)).B);
        int edge = S(v2[i] - v2[j]) ^ S(v2[i] - mid);
        // DBGG("edge = " , edge);
        tmp.pb(edge);
    }
    REP(i , 0 , v2.size()){
        int j = (i + 1) % v2.size();
        int edge = S(v2[i] - v2[j]) ^ S(v2[i] - mid);
        tmp.pb(edge);
    }
    // cout << hashval << endl;
    // for(auto to : tmp) cout << to << " " ; cout << endl;
    sovler.solveinit(tmp);
    REP(i , 1 , v2.size() + 1){
        int j = i + v2.size() - 1;
        // DBGG("second = " , sovler.query(i , j));
        if(hashval == sovler.query(i , j)) cnt ++;
    }
    // DBGG("cnt = " , cnt);
    return cnt >= 1;
}
int n , m;
PII a[MAX] , b[MAX];

int32_t main(){
    IOS;
    cin >> n >> m;
    x.n = n;
    y.n = m;
    REP(i , 1 , n + 1) cin >> x.x[i].A >> x.x[i].B;
    REP(i , 1 , m + 1) cin >> y.x[i].A >> y.x[i].B;

    v1 = x.solve() , v2 = y.solve();
    

    // if(x.CalcArea(v1) != y.CalcArea(v2) || v1.size() != v2.size())
    //     return cout << "NO" << endl , 0;
    // else {
        v1.pop_back() , v2.pop_back();
        // for(auto to : v1) DBGG(to.A , to.B);
        //     cout << endl;

        // for(auto to : v2) DBGG(to.A , to.B);

        // cout << "second place" << endl;
        AC = rand() % 100 * 2 + 1;
        int q = solve();
        // cout << "-----------------------" << endl;
        // AC = rand() % 100 * 2 + 1;
        // int w = solve();
        // DB4("q = " , q , "w = " , w);
        if(q) 
             cout << "YES" << endl;
        else cout << "NO" << endl;
    // }
    return 0;
}