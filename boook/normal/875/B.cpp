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
#define MAX 400000
#define INF 0x3f3f3f3f

class djs{
public:
    int x[MAX] , siz[MAX];
    void init(){ REP(i , 0 , MAX) x[i] = i , siz[i] = 1; }
    int Find(int now){ return x[now] == now ? now : x[now] = Find(x[now]); }
    void Union(int a , int b){
        a = Find(a) , b = Find(b);
        x[a] = b;
        siz[b] += siz[a];
    }
    int operator[](int now){ return Find(now); }
} ds;
int n , x[MAX] , ok[MAX];
int32_t main(){
    ds.init();
    IOS , cin >> n;
    REP(i , 1 , n + 1){
        cin >> x[i];
    }
    cout << 1 ;
    REP(i , 1 , n + 1){
        ok[x[i]] = 1;
        if(ok[x[i] + 1]) ds.Union(x[i] , x[i] + 1);
        if(ok[x[i] - 1]) ds.Union(x[i] , x[i] - 1);
        if(ok[n] == 0) cout << " " << i + 1 ;
        else {
            int sum = ds.siz[ds[n]];
            // DBGG("sum = " , sum);
           cout << " " << i - (sum - 1);
        }
    }
    cout << endl;
    return 0;
}