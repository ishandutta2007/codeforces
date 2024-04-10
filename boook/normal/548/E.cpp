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
#define MAX 600000
#define INF 0x3f3f3f3f

int dv[MAX] , p[MAX] , dpo = 0;
void pre(){
    REP(i , 2 , MAX){
        if(dv[i] == 0) dv[i] = i , p[dpo ++] = i;
        REP(j , 0 , dpo){
            int tmp = p[j] * i;
            if(tmp >= MAX) break;
            dv[tmp] = p[j];
            if(i % p[j] == 0) break;
        }
    }
}
int n , m;
int x[MAX] , use[MAX] , res[MAX];
vector<PII> v[MAX];
vector<int> tmp;
void solve(int floor , int ty , int val , int num){
    if(floor == tmp.size()){
        if(val != 1) v[ty].pb(mp(val , (num % 2 == 0) ? -1 : 1));
        return ;
    }
    else {
        solve(floor + 1 , ty , val , num);
        solve(floor + 1 , ty , val * tmp[floor] , num + 1);
    }
}

int32_t main(){
    pre();
    cin >> n >> m;
    REP(i , 0 , n){
        cin >> x[i];
        tmp.clear();
        while(x[i] != 1){
            int val = dv[x[i]];
            while(x[i] % val == 0){
                x[i] /= val;
            }
            tmp.pb(val);
        }
        solve(0 , i , 1 , 0);
    }
    int ans = 0 , ss = 0;
    REP(i , 0 , m){
        int q , cnt = 0;
        cin >> q;
        q--;
        for(auto now : v[q]){
            if(use[q] == 1) res[now.A] --;
            cnt += now.B * res[now.A];
            if(use[q] == 0) res[now.A] ++;
        }

        if(use[q] == 0) ans += ss - cnt , ss ++;
        else ans -= (ss - 1) - cnt , ss --;

        use[q] ^= 1;
        cout << ans << endl;
    }    
    return 0;
}