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
#define MAX 200
#define INF 0x3f3f3f3f

int n , m;
int x[MAX];
set<int> cc;
int32_t main(){
    IOS;
    cin >> n >> m;

    REP(i , 0 , n) cin >> x[i];
    int up = 0;
    REP(i , 0 , n){
        int tmp = min((int)(sqrt(x[i] + 1)) + 1 , x[i]);
        up = max(up , tmp);
        cc.insert(x[i]);
        REP(j , 1 , tmp){
            if(x[i] % j == 0) cc.insert(x[i] / j);
            else cc.insert(x[i] / j + 1);
        }
    }
    REP(i , 1 , up + 1) cc.insert(i);
    auto now = cc.end(); now --;
    if(cc.size()){
        while(1){
            int val = *now;
            int res = 0 , bb = 0;
            REP(i , 0 , n){
                if(x[i] % val == 0) bb += x[i] / val;
                else {
                    int tmp = ((x[i] / val) + 1) * val - x[i];
                    bb += (x[i] / val) + 1;
                    res += tmp;
                    if(res > m) break;
                }
            }
            if(res <= m){
                int qqq = m - res;
                if(qqq % bb == 0) val += qqq / bb;
                else val += qqq / bb;
                // while(res + bb <= m) res += bb , val ++;
                cout << val << endl;
                return 0;
            }
            if(now == cc.begin()) break;
            now --;
        }
    }
    return 0;
}