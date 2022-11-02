/*input
100
1 1 0 0 0 1 0 0 1 0 0 0 1 0 1 1 0 1 0 0 0 0 0 0 0 0 0 1 1 0 0 1 0 1 1 0 1 1 1 1 1 1 0 1 0 1 0 1 0 1 0 0 0 1 0 1 1 0 1 1 1 0 0 1 0 0 1 1 1 0 1 1 0 0 0 1 0 0 0 0 1 1 1 0 1 1 1 1 1 1 0 1 0 0 1 1 1 0 1 1 
*/
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
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 100900
#define INF 0x3f3f3f3f

vector<pair<PII , int>> ans;

int n , x[MAX];
pair<PII , int> trs(int a , int b , int c){
    return mp(mp(a + 1 , b + 1) , c + 1);
}
void G(int a , int b , int c){
    // DB4(a , b , c , "??");
    if(b - a != c - b || a < 0) {
        cout << "WA" << endl;
        exit(0);
    }
    ans.pb(trs(a , b , c));
    x[a] ^= 1; x[b] ^= 1; x[c] ^= 1;
}
PII dp[(1 << 15)];
void solve(int nn){
    queue<int> qu;
    REP(i , 0 , (1 << nn)) dp[i] = mp(-1 , -1);
    dp[0] = mp(0 , 0) , qu.push(0);

    while(qu.size()){
        int now = qu.front(); qu.pop();
        REP(i , 0 , nn){
            REP(j , 1 , nn + 1){
                if(i + j < nn && i - j >= 0){
                    int pat = now;
                    pat ^= (1 << (i));
                    pat ^= (1 << (i - j));
                    pat ^= (1 << (i + j));
                    if(dp[pat].A == -1){
                        dp[pat] = mp(i , j);
                        qu.push(pat);
                    }
                }
            }
        }
    }
    int tot = 0;
    REP(i , 0 , nn) if(x[i] == 1) tot |= (1 << i);

    if(dp[tot].A == -1){
        cout << "NO" << endl;
        exit(0);
    }
    else {
        while(tot != 0){
            PII y = dp[tot];
            G(y.A - y.B , y.A , y.A + y.B);
            tot ^= (1 << (y.A - y.B));
            tot ^= (1 << (y.A));
            tot ^= (1 << (y.A + y.B));
        }
    }
}
int32_t main(){
    IOS;
    cin >> n;
    REP(i , 0 , n) cin >> x[i];

    if(n <= 12){
        solve(n);
        cout << "YES" << endl;
        cout << ans.size() << endl;
        for(auto to : ans) cout << to.A.A << " " << to.A.B << " " << to.B << endl; 
        return 0;
    }

    int nn = n;
    while(nn > 12){
        if(x[nn - 3] == 0 && x[nn - 2] == 0 && x[nn - 1] == 0);

        if(x[nn - 3] == 1 && x[nn - 2] == 0 && x[nn - 1] == 0) G(nn - 5 , nn - 4 , nn - 3);
        if(x[nn - 3] == 0 && x[nn - 2] == 1 && x[nn - 1] == 0) G(nn - 6 , nn - 4 , nn - 2);
        if(x[nn - 3] == 0 && x[nn - 2] == 0 && x[nn - 1] == 1) G(nn - 7 , nn - 4 , nn - 1);

        if(x[nn - 3] == 1 && x[nn - 2] == 1 && x[nn - 1] == 0) G(nn - 4 , nn - 3 , nn - 2);
        if(x[nn - 3] == 1 && x[nn - 2] == 0 && x[nn - 1] == 1) G(nn - 5 , nn - 3 , nn - 1);
        if(x[nn - 3] == 0 && x[nn - 2] == 1 && x[nn - 1] == 1){
            vector<int> sol;
            RREP(i , nn - 4 , nn - 6) if (x[i] == 1) sol.pb(i);
            if(sol.size() == 3){
                G(nn - 6 , nn - 4 , nn - 2);
                G(nn - 9 , nn - 5 , nn - 1);
            }
            else {
                while(sol.size() != 2) sol.pb(nn - 7);
                G(sol[0] + sol[0] - (nn - 1) , sol[0] , nn - 1);
                G(sol[1] + sol[1] - (nn - 2) , sol[1] , nn - 2);
            }
        }

        if(x[nn - 3] == 1 && x[nn - 2] == 1 && x[nn - 1] == 1) G(nn - 3 , nn - 2 , nn - 1);
        nn -= 3;
    }

    // REP(i , 0 , n) cout << x[i] ; cout << endl;
    solve(nn);

    REP(i , 0 , n) if(x[i] == 1) { cout << "WA10" << endl; exit(0); }
    if(ans.size() > n / 3 + 12) { cout << "WA87" << endl; exit(0); }

    cout << "YES" << endl;
    cout << ans.size() << endl;
    for(auto to : ans) cout << to.A.A << " " << to.A.B << " " << to.B << endl; 

    return 0;
}