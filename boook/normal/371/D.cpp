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
#define MAX 300000
#define INF 0x3f3f3f3f

class djs{
public:
    int x[MAX] , val[MAX];
    void init(){ REP(i , 0 , MAX) x[i] = i , val[i] = 0; }
    int Find(int now){ return x[now] == now ? now : x[now] = Find(x[now]); }
    void Union(int a , int b){
        a = Find(a) , b = Find(b);
        x[a] = b , val[b] += val[a];
    }
    int operator[](int now){ return Find(now); }
}ds;
int n , m , x[MAX];
int32_t main(){
    ds.init();
    cin >> n;
    REP(i , 1 , n + 1) cin >> x[i];
    cin >> m;
    REP(t , 1 , m + 1){
        int a , b , c;
        cin >> a;
        if(a == 1){
            cin >> b >> c;
            ds.val[ds[b]] += c;
            while(ds.val[ds[b]] >= x[ds[b]]){
                if(ds[b] == n){
                    ds.val[ds[b]] = x[n];
                    break;
                }
                ds.val[ds[b]] -= x[ds[b]];
                ds.Union(ds[b] , ds[b] + 1);
            }
        }
        else {
            cin >> b;
            if(ds[b] != b) cout << x[b] << endl;
            else cout << ds.val[ds[b]] << endl;
        }
    }
    return 0;
}