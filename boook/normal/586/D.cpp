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
#define MAX 
#define INF 0x3f3f3f3f

int t , n , m;
string s[5];
int IN(int a , int b){
    if(a >= 0 && b >= 0 && a < 3 && b < s[0].size() && s[a][b] == '.') return 1;
    return 0; 
}
int use[4][5050];
int32_t main(){
    cin >> t;
    REP(times , 0 , t){
        cin >> n >> m;
        REP(i , 0 , 3) cin >> s[i] , s[i] += "..........";
        PII now = mp(0 , 0);
        REP(i , 0 , 3) if(s[i][0] == 's') now = mp(i , 0);
        queue<PII> qu;
        qu.push(now);
        int ok = 0;
        MEM(use , 0);
        while(qu.size()){

            int x = qu.front().A , y = qu.front().B; qu.pop();
            if(y > n) ok = 1;
            if(IN(x , y + 1) && IN(x - 1 , y + 1) && IN(x - 1 , y + 2) && IN(x - 1 , y + 3)){
                if(use[x - 1][y + 3] == 0)
                    use[x - 1][y + 3] = 1 , qu.push(mp(x - 1 , y + 3));
            }
            if(IN(x , y + 1) && IN(x + 0 , y + 1) && IN(x + 0 , y + 2) && IN(x + 0 , y + 3)){
                if(use[x + 0][y + 3] == 0)
                    use[x + 0][y + 3] = 1 , qu.push(mp(x + 0 , y + 3));
            }
            if(IN(x , y + 1) && IN(x + 1 , y + 1) && IN(x + 1 , y + 2) && IN(x + 1 , y + 3)){
                if(use[x + 1][y + 3] == 0)
                    use[x + 1][y + 3] = 1 , qu.push(mp(x + 1 , y + 3));
            }
        }
        cout << ((ok == 1) ? "YES" : "NO") << endl;
    }
    return 0;   
}