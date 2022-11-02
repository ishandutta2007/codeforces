/*input
5
2 4 5 1 3
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
#define int long long
#define MAX 1000090
#define INF 0x3f3f3f3f

struct djs{
    int x[MAX];
    void init(){ REP(i , 0 , MAX) x[i] = i; }
    int Find(int a){ return a == x[a] ? a : x[a] = Find(x[a]); }
    void Union(int a , int b){ x[Find(a)] = Find(b); }
    int operator[](int a){ return Find(a); }
} ds;

int n , x[MAX];
int R(){
    int val = 0;
    REP(i , 0 , 15) val = val * 10 + rand() % 10;
    return val;
}

int32_t main(){
    IOS;
    cin >> n;
    REP(i , 1 , n + 1) cin >> x[i];
    // n = 3030;
    // REP(i , 1 , n + 1) x[i] = i;
    // REP(i , 1 , n * 3 + 0 + 1){
    // REP(i , 1 , n * 7 + 1 + 1){
     /*   int a = R() % n + 1;
        int b = R() % n + 1;
        while(a == b) a = R() % n + 1 , b = R() % n + 1;
        swap(x[a] , x[b]);
    }*/
    int cnt = 0;
    ds.init();
    REP(i , 1 , n + 1) ds.Union(x[i] , i);
    REP(i , 1 , n + 1) cnt += ds[i] == i;
    // REP(i , 1 , n + 1) if(x[i] == i) cnt ++;
    int base = n;
    if((base + n * 3 + 0) % 2 == cnt % 2) cout << "Petr" << endl;
    if((base + n * 7 + 1) % 2 == cnt % 2) cout << "Um_nik" << endl;

    // REP(i , 1 , n + 1) cout << x[i] << " " ; cout << endl;
    return 0;
}