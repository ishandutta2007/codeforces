#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j)       for(int i = 0 ; i < j ; i++)
#define REPNM(i,j,k)   for(int i = j ; i < k ; i++)
#define RREP(i,j,k)    for(int i = j ; i >=k ; i--)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
#define PII pair<int , int>
#define VI  vector<int> 
#define VPII vector<PII>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
///------------------------------------------------------------
#define int long long
#define MAX 100900
#define Max 510
#define INF 100000000000000LL

int n , m , k;
int c[MAX] , ty[MAX];
class{
public:
    int x[MAX];
    void init(){ REP(i , MAX) x[i] = i; }
    int Find(int now){ return now == x[now] ? now : x[now] = Find(x[now]); }
    void Union(int a , int b){ x[Find(a)] = Find(b); }
    int operator[](int now) { return Find(now); }
}ds;

int p[Max][Max] , use[MAX];

int check(){
    REPNM(i , 1 , n + 1){
        int tmp = ds[i];
        if(use[ty[i]] == 0) use[ty[i]] = tmp;
        else if(use[ty[i]] != tmp) return 0;
    }
    return 1;
}
int32_t main(){
    ds.init();
    cin >> n >> m >> k;
    REPNM(i , 1 , k + 1) cin >> c[i];
    REPNM(i , 1 , k + 1) c[i] += c[i - 1];

    int po = 1;
    REPNM(i , 1 , n + 1){
        ty[i] = po;
        if(c[po] == i) po++;
    }
    assert(po == k + 1);
    REPNM(i , 1 , k + 1) 
        REPNM(j , 1 , k + 1)
            p[i][j] = INF;

    REPNM(i , 1 , k + 1) p[i][i] = 0;

    REPNM(i , 1 , m + 1){
        int q , w , e;
        cin >> q >> w >> e;
        if(e == 0) ds.Union(q , w);
        if(ty[q] != ty[w]){
            p[ty[q]][ty[w]] = min(p[ty[q]][ty[w]] , e);
            p[ty[w]][ty[q]] = min(p[ty[w]][ty[q]] , e);
        }
    }
    if(check() == 0) return puts("No");
    puts("Yes");
    REPNM(l , 1 , k + 1){
        REPNM(i , 1 , k + 1){
            REPNM(j , 1 , k + 1){
                p[i][j] = min(p[i][j] , p[i][l] + p[l][j]);
            }
        }
    }
    REPNM(i , 1 , k + 1){
        REPNM(j , 1 , k + 1) if(p[i][j] == INF) p[i][j] = -1;
        cout << p[i][1];
        REPNM(j , 2 , k + 1) cout << " " << p[i][j];
        cout << "\n";
    }
    return 0;
}