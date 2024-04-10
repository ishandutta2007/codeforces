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
///------------------------------------------------------------
#define MAX 500900
#define INF 0x3f3f3f3f

class djs{
public:
    int x[MAX] , l[MAX];
    void init(){ REP(i , 0 , MAX) x[i] = l[i] = i; }
    int Find(int now){ return x[now] == now ? now : x[now] = Find(x[now]); }
    void Union(int a , int b){
        a = Find(a) , b = Find(b);
        x[a] = b;
        l[b] = min(l[a] , l[b]);
    }
    int operator[](int now){ return Find(now); }
} ds;
int n , m , k;
string s;
int x[MAX] , l[MAX] , r[MAX];
int32_t main(){
    ds.init();
    IOS;
    cin >> n >> m >> k;
    cin >> s;

    stack<int> cc;
    REP(i , 0 , s.size()){
        if(s[i] == '(') cc.push(i + 1);
        else r[cc.top()] = i + 1 , l[i + 1] = cc.top() , cc.pop();
    }
    int now = k;
    cin >> s;
    REP(i , 0 , s.size()){
        if(s[i] == 'L') now = ds.l[ds[now]] - 1;
        else if(s[i] == 'R') now = ds[ds[now] + 1];
        else if(s[i] == 'D'){
            if(r[now]) now = r[now];
            int to = l[now];
            now = ds[ds[now] + 1];
            while(ds.l[ds[now]] - 1 >= to){
                ds.Union(ds.l[ds[now]] - 1 , now);
            }
            if(now == n + 1) now = ds.l[ds[now]] - 1;
        }
    }
    REP(i , 1 , n + 1){
        if(ds[i] == i){
            if(l[i]) cout << ')';
            if(r[i]) cout << '(';
        }
    }
    cout << endl;
    return 0;
}