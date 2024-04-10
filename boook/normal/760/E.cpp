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
#define MAX 100900
#define INF 0x3f3f3f3f
#define N 320

int lx[N] , ly[N];
int n , x[MAX] , use[MAX];
void update(int to){
    int id = to / N;
    lx[id] = ly[id] = 0;
    REP(i , id * N , (id + 1) * N) use[i] = 0;
    stack<int> cc;
    REP(i , id * N , (id + 1) * N){
        if(x[i] == 0) continue;
        if(x[i] > 0) cc.push(i);
        if(x[i] < 0){
            if(cc.size()){
                use[cc.top()] = 1;
                use[i] = 1;
                cc.pop();
            }
            else lx[id] ++;
        }
    }
    ly[id] = cc.size();
}
int query(){
    int id = n / N , have = 0;
    RREP(i , id , 0){
        if(ly[i] > have){
            RREP(j , (i + 1) * N - 1 , i * N){
                if(x[j] > 0 && use[j] == 0){
                    if(have == 0) return x[j];
                    else have --;
                }
            }
        }
        else have = have - ly[i] + lx[i];
    }
    return -1;
}
int32_t main(){
    IOS , cin >> n;
    REP(times , 1 , n + 1){
        int to , ty;
        cin >> to >> ty;
        if(ty == 0) x[to] = -1;
        else cin >> x[to];
        update(to);
        cout << query() << endl;
    }
    return 0;
}