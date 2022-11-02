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
#define MAX 1010
#define INF 0x3f3f3f3f

int n , m , k , x[400000][4];
int cnt[MAX][MAX][28];
int yes[MAX][MAX] , no[MAX][MAX];
int pre[MAX][MAX] , to[MAX][MAX][28];
int s[MAX][MAX] , ty[400000];

int32_t main(){
    IOS;
    cin >> n >> m >> k;
    char cc;
    REP(i , 1 , n + 1) REP(j , 1 , m + 1) cin >> cc , s[i][j] = (int)cc;

    REP(i , 1 , k + 1){
        REP(j , 0 , 4) cin >> x[i][j];
        cin >> cc , ty[i] = (int)cc;
    }
    
    REP(i , 0 , 26){
        REP(ii , 1 , n + 1) REP(jj , 1 , m + 1){
            yes[ii][jj] = 0 , no[ii][jj] = 0;
        } 
        REP(j , 1 , k + 1){
            int a = x[j][0] , b = x[j][1];
            int c = x[j][2] , d = x[j][3];

            if(ty[j] - 'a' == i){
                yes[a + 0][b + 0] ++ , yes[c + 1][b + 0] --;
                yes[a + 0][d + 1] -- , yes[c + 1][d + 1] ++;
            }
            else {
                 no[a + 0][b + 0] ++ ,  no[c + 1][b + 0] --;
                 no[a + 0][d + 1] -- ,  no[c + 1][d + 1] ++;
            }
        }
        REP(ii , 1 , n + 1) REP(jj , 1 , m + 1){
            yes[ii][jj] += yes[ii - 1][jj] + yes[ii][jj - 1] - yes[ii - 1][jj - 1];
             no[ii][jj] +=  no[ii - 1][jj] +  no[ii][jj - 1] -  no[ii - 1][jj - 1];
        }

        REP(ii , 1 , n + 1) REP(jj , 1 , m + 1){
            if(s[ii][jj] - 'a' == i) cnt[ii][jj][i] = k - no[ii][jj];
            if(s[ii][jj] - 'a' != i) cnt[ii][jj][i] = yes[ii][jj];
        }
    }

    REP(ii , 1 , n + 1) REP(jj , 1 , m + 1){
        REP(i , 0 , 26) to[ii][jj][0] += cnt[ii][jj][i] * i;
        int l = cnt[ii][jj][0] , r = k - cnt[ii][jj][0];
        REP(i , 1 , 26){
            to[ii][jj][i] = to[ii][jj][i - 1] + l - r;
            l += cnt[ii][jj][i];
            r -= cnt[ii][jj][i];
        }
        pre[ii][jj] = to[ii][jj][s[ii][jj] - 'a'];
    }
    REP(ii , 1 , n + 1) REP(jj , 1 , m + 1)
        pre[ii][jj] += pre[ii - 1][jj] + pre[ii][jj - 1] - pre[ii - 1][jj - 1];

    REP(i , 0 , 26) REP(ii , 1 , n + 1) REP(jj , 1 , m + 1) 
        to[ii][jj][i] += to[ii - 1][jj][i] + to[ii][jj - 1][i] - to[ii - 1][jj - 1][i];

    int ans = 1e18;

    REP(i , 1 , k + 1){
        int a = x[i][0] , b = x[i][1];
        int c = x[i][2] , d = x[i][3];
        int val = pre[n][m] , tmp = ty[i] - 'a';
        val -= pre[c][d] - pre[a - 1][d] - pre[c][b - 1] + pre[a - 1][b - 1];
        val += to[c][d][tmp] - to[a - 1][d][tmp] - to[c][b - 1][tmp] + to[a - 1][b - 1][tmp];
        ans = min(ans , val);
    }
    cout << ans << endl;
    return 0;
}