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
#define MAX 100900
#define INF 0x3f3f3f3f

int n , x[MAX] , ans;
vector<int> v[MAX];

int siz[MAX] , centroid[MAX];
void compute_size(int now , int fa){
    siz[now] = 1;
    for(auto to : v[now]){
        if(to == fa || centroid[to]) continue;
        compute_size(to , now);
        siz[now] += siz[to];
    }
}
PII find_centroid(int now , int fa , int all){
    PII res = mp(INF , 0);
    int sum = 1 , big = 0;
    for(auto to : v[now]){
        if(to == fa || centroid[to]) continue;
        res = min(res , find_centroid(to , now , all));
        big = max(big , siz[to]);
        sum += siz[to];
    }
    big = max(big , all - sum);
    res = min(res , mp(big , now));
    return res;
}
void get_dist(int now , int fa , int dis , vector<int> &ds){
    ds.pb(dis);
    for(auto to : v[now]){
        if(to == fa || centroid[to]) continue;
        get_dist(to , now , dis ^ x[to] , ds);
    }
}
int solve(int now){
    compute_size(now , -1);
    int s = find_centroid(now , -1 , siz[now]).B;
    centroid[s] = 1;
    for(auto to : v[s]){
        if(centroid[to] == 0) solve(to);
    }

    vector<int> ds , cnt0(30 , 0) , cnt1(30 , 0);
    for(auto to : v[s]){
        if(centroid[to]) continue;
        ds.clear();
        get_dist(to , s , x[s] ^ x[to] , ds);
        for(auto ii : ds){
            ans += ii;
            int d = ii ^ x[s];
            REP(i , 0 , 30){
                if(d & (1 << i))
                    ans += (1 << i) * cnt0[i];
                else 
                    ans += (1 << i) * cnt1[i];
            }
        }
        for(auto ii : ds){
            REP(i , 0 , 30){
                if(ii & (1 << i))
                     cnt1[i] ++;
                else cnt0[i] ++;
            }
        }
    }
    centroid[s] = 0;
}
int32_t main(){
    cin >> n;
    REP(i , 1 , n + 1) cin >> x[i];
    REP(i , 2 , n + 1){
        int a , b;
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    REP(i , 1 , n + 1) ans += x[i];
    solve(1);
    cout << ans << endl;
    return 0;
}