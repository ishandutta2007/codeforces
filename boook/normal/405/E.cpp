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

inline int rit(){
    char c = getchar();
    int res = 0;
    while(!isdigit(c)) c = getchar();
    while(isdigit(c)) res = (res << 1) + (res << 3) + c - '0' , c = getchar();
    return res;
}

int n , m , use[MAX];
vector<PII> v[MAX];
int DFS(int now){
    queue<int> qu;
    for(auto to : v[now]){
        if(use[to.B]) continue;
        use[to.B] = 1;
        int tmp = DFS(to.A);
        if(tmp) printf("%d %d %d\n", tmp , to.A , now);
        else qu.push(to.A);
    }
    while(qu.size() >= 2){
        int a = qu.front(); qu.pop();
        int b = qu.front(); qu.pop();
        printf("%d %d %d\n", a , now , b);
    }
    if(qu.size() == 0) return 0;
    else return qu.front();
}
int32_t main(){
    n = rit() , m = rit();
    REP(i , 1 , m + 1){
        int a , b;
        cin >> a >> b;
        v[a].pb(mp(b , i));
        v[b].pb(mp(a , i));
    }
    if(m % 2 == 1) puts("No solution");
    else DFS(1);
    return 0;
}