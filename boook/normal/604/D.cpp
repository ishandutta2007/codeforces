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
#define MAX 1000900
#define INF 0x3f3f3f3f
#define mod 1000000007LL

class djs{
    public: 
    int x[MAX];
    void init(){ REP(i , 0 , MAX) x[i] = i; }
    int Find(int now){ return x[now] == now ? now : x[now] = Find(x[now]); }
    void Union(int a , int b){ x[Find(a)] = Find(b); }
    int operator[](int now){ return Find(now); }
}ds;
int n , m;
int32_t main(){
    ds.init();
    cin >> n >> m;
    int ans = 1;
    if(m == 0){
        REP(i , 1 , n) ans = ans * n % mod;
    }
    else if(m == 1){
        REP(i , 0 , n) ans = ans * n % mod;
    }
    else{
        REP(i , 1 , n){
            ds.Union(i , i * m % n);
        }
        REP(i , 1 , n){
            if(ds[i] == i) ans = ans * n % mod;
        }
    }
    cout << ans << endl;
    return 0;
}