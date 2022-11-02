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
#define MAX 40
#define INF 2147483647

int n , x[MAX][3] , N;
map<PII , PII> cc;
void pre(int floor , int a , int b , int c , int now){
    if(floor > N){
        if(cc.find(mp(b - a , c - a)) == cc.end())
            cc[mp(b - a , c - a)] = mp(a , now);
        else if(cc[mp(b - a , c - a)].A < a)
            cc[mp(b - a , c - a)] = mp(a , now);
    }
    else {
        pre(floor + 1 , a + x[floor][0] , b + x[floor][1] , c , now * 3 + 2);
        pre(floor + 1 , a + x[floor][0] , b , c + x[floor][2] , now * 3 + 1);
        pre(floor + 1 , a , b + x[floor][1] , c + x[floor][2] , now * 3 + 0);
    }
}
int mm = -INF , tma , tmb;
void DFS(int floor , int a , int b , int c , int now){
    if(floor > n){
        PII need = mp(a - b , a - c);
        if(cc.find(need) != cc.end()){
            if(a + cc[need].A > mm) mm = a + cc[need].A , tma = cc[need].B , tmb = now;
        }
    }
    else {
        DFS(floor + 1 , a + x[floor][0] , b + x[floor][1] , c , now * 3 + 2);
        DFS(floor + 1 , a + x[floor][0] , b , c + x[floor][2] , now * 3 + 1);
        DFS(floor + 1 , a , b + x[floor][1] , c + x[floor][2] , now * 3 + 0);
    }
}
int32_t main(){
    IOS;
    cin >> n;
    REP(i , 1 , n + 1) REP(j , 0 , 3) cin >> x[i][j];

    N = min(n , 12);
    pre(1 , 0 , 0 , 0 , 0);
    DFS(N + 1 , 0 , 0 , 0 , 0);

    if(mm != -INF){
        stack<int> tmp;
        int val = tma;
        while(N > 0) tmp.push(val % 3) , val /= 3 , N --;
        while(tmp.size()){
            if(tmp.top() == 0) cout << "MW" << endl;
            if(tmp.top() == 1) cout << "LW" << endl;
            if(tmp.top() == 2) cout << "LM" << endl;
            tmp.pop();
        }
        N = min(n , 12);
        val = tmb;
        while(n > N) tmp.push(val % 3) , val /= 3 , n --;
        while(tmp.size()){
            if(tmp.top() == 0) cout << "MW" << endl;
            if(tmp.top() == 1) cout << "LW" << endl;
            if(tmp.top() == 2) cout << "LM" << endl;
            tmp.pop();
        }
    }
    if(mm == -INF) cout << "Impossible" << endl;
    return 0;
}