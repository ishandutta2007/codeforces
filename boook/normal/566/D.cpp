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
#define MAX 200900
#define INF 0x3f3f3f3f

class djs{
public:
    int x[MAX];
    void init(){ REP(i , 0 , MAX) x[i] = i; }
    int Find(int now){ return x[now] == now ? now : x[now] = Find(x[now]); }
    void Union(int a , int b){ x[Find(a)] = Find(b); }
    int operator[](int now){ return Find(now); }
} ds , h;
int n , m , q , w , e;
inline int rit(){
    char c = getchar();
    int cnt = 0;
    while(!isdigit(c)) c = getchar();
    while(isdigit(c)) cnt = cnt * 10 + c - '0' , c = getchar();
    return cnt;
}
int32_t main(){
    ds.init() , h.init();
    n = rit() , m = rit();
    REP(i , 1 , m + 1){
        q = rit() , w = rit() , e = rit();

        if(q == 1) ds.Union(w , e);
        else if(q == 2){
            int now = h[w];
            while(now < e){
                ds.Union(now , now + 1);
                h.Union(now , now + 1);
                now = h[now];
            }
        }
        else {
            if(ds[w] == ds[e]) puts("YES");
            else puts("NO");
        }
    }
    return 0;
}