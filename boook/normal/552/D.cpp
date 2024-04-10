#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 2010
#define INF 0x3f3f3f3f

int n;
int x[MAX][2];
int32_t main(){
    cin >> n;
    REP(i , 0 , n){
        cin >> x[i][0] >> x[i][1];
    }
    int ans = n * (n - 1) * (n - 2) / 6;

    REP(i , 0 , n){
        map<PII , int> dd;
        int cnt = 0;
        REP(j , i + 1 , n){
            int xx = x[i][0] - x[j][0];
            int yy = x[i][1] - x[j][1];
            if(xx == 0 && yy == 0) cnt ++;
            else {
                if(xx == 0) yy = 1;
                else if(yy == 0) xx = 1;
                else if(xx < 0) xx *= -1 , yy *= -1;
                int gg = __gcd(xx , yy);
                if(xx != 0 && yy != 0) xx /= gg , yy /= gg;
                dd[mp(xx , yy)] ++;
            }
        }
        for(auto to : dd){
            to.B += cnt;
            int tmp = (to.B) * (to.B - 1) / 2;
            ans -= tmp;
        }
    }
    cout << ans << endl;
    return 0;
}