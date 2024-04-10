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
#define MAX 200090
#define INF 0x3f3f3f3f

int n , x[MAX];
int cnt[MAX] , pre[MAX] , use[MAX];
int oo[MAX] , att[MAX] , bit[MAX];
void update(int from , int val){
    for(int i = from ; i < MAX ; i += i & -i)
        bit[i] += val;
}
int query(int from){
    int res = 0;
    for(int i = from ; i > 0 ; i -= i & -i){
        res += bit[i];
    }
    return res;
}
int Find(int l , int r){
    return query(r) - query(l - 1);
}
vector<int> h[MAX];
int32_t main(){
    IOS;
    cin >> n;
    REP(i , 1 , n + 1) cin >> x[i];
    REP(i , 1 , n + 1) cnt[x[i]] ++;
    REP(i , 1 , MAX) pre[i] = pre[i - 1] + cnt[i];

    REP(i , 1 , n + 1){
        h[x[i]].pb(i);
    }
    int ppp = 0;
    REP(i , 1 , MAX){
        if(h[i].size() == 0) continue;
        int ww = 0;
        while(ww < h[i].size() && h[i][ww] < ppp) ww ++;
        int ccnt = 1;
        REP(j , ww , h[i].size()){
            int id = h[i][j];
            oo[id] = pre[x[id] - 1] + ccnt;
            ccnt ++;
            ppp = id;
        }
        REP(j , 0 , ww){
            int id = h[i][j];
            oo[id] = pre[x[id] - 1] + ccnt;
            ccnt ++;
            ppp = id;
        }
    }


    REP(i , 1 , n + 1){
        // cout << oo[i] << " " ;
        att[oo[i]] = i;
    }

    // cout << endl;
    int ans = 0 , lat = 1;
    REP(i , 1 , n + 1) update(i , 1);
    REP(i , 1 , n + 1){
        if(att[i] >= lat){
            ans += Find(lat , att[i]);
            update(att[i] , -1);
            lat = att[i];
        }
        else {
            ans += Find(lat , n) + Find(1 , att[i]);
            update(att[i] , -1);
            lat = att[i];
        }
    }
    cout << ans << endl;
    return 0;
}