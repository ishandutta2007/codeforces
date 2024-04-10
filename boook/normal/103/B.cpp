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
#define MAX 100000
#define INF 0x3f3f3f3f

int n , m;
int x[MAX][2];
class djs{
public:
    int x[MAX];
    void init(){ REP(i , 0 , MAX) x[i] = i; }
    int Find(int now){ return x[now] == now ? now : x[now] = Find(x[now]); }
    void Union(int a , int b){ x[Find(a)] = Find(b); }
    int operator[](int now){ return Find(x[now]); }
}ds;
int32_t main(){
    ds.init();
    cin >> n >> m;
    REP(i , 0 , m){
        cin >> x[i][0] >> x[i][1];
        ds.Union(x[i][0] , x[i][1]);
    }
    int ok = (n == m);
    REP(i , 1 , n + 1){
        if(ds[i] != ds[1]) ok = 0;
    }
    if(ok) cout << "FHTAGN!" << endl;
    else cout << "NO" << endl;
    return 0;
}