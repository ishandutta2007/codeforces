#include <bits/stdc++.h>
using namespace std;
#define REP(i , j , k) for(int i = j ; i < k ; i ++)
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define pb push_back
#define int long long
#define MAX 100900

struct djs{
    int x[MAX] , v[MAX];
    void init(){ REP(i , 0 , MAX) x[i] = i; }
    int Find(int now){ return x[now] == now ? now : x[now] = Find(x[now]); }
    void Union(int a , int b){
        a = Find(a);
        b = Find(b);
        if(a != b){
            x[a] = b;
            v[b] += v[a];
        }
    }
    int operator[](int now){ return Find(x[now]); }
} ds;

int n , m , k , a[MAX] , sol[MAX] , e[MAX][3];
int cmp(int a , int b){
    return e[a][2] < e[b][2];
}
int32_t main(){
    IOS;
    ds.init();
    cin >> n >> m >> k;
    REP(i , 1 , k + 1) cin >> a[i];
    REP(i , 1 , m + 1) cin >> e[i][0] >> e[i][1] >> e[i][2];
    
    REP(i , 1 , k + 1) ds.v[a[i]] = 1;

    int ans = 0;
    REP(i , 1 , m + 1) sol[i] = i;
    sort(sol + 1 , sol + 1 + m , cmp);
    REP(i , 1 , m + 1){
        int idx = sol[i];
        if(ds[e[idx][0]] != ds[e[idx][1]]){
            ans = e[idx][2];
            ds.Union(e[idx][0] , e[idx][1]);
            int tmp = ds[e[idx][0]];
            if(ds.v[tmp] == k){
                break;
            }
        }
    }
    REP(i , 1 , k + 1) cout << ans << " " ; cout << endl;
    return 0;
}