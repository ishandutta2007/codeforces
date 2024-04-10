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
#define MAX 100090
#define INF 0x3f3f3f3f

int n , N = 1000000000LL , pre[MAX] , p[MAX][2];
int l , r , x , y;
double d;
map<int , int> cc;
int DIS(int a , int b){
    return (p[a][0] - p[b][0]) * (p[a][0] - p[b][0])
         + (p[a][1] - p[b][1]) * (p[a][1] - p[b][1]);
}
int ID(int a){
    int aa = p[a][0] / d;
    int bb = p[a][1] / d;
    return aa * N + bb;
}
int solve(){
    l = r = p[1][0] , x = y = p[1][1];
    REP(i , 1 , n + 1){
        l = min(l , p[i][0]);
        r = max(r , p[i][0]);
        x = min(x , p[i][1]);
        y = max(y , p[i][1]);
    }
    int ans = DIS(1 , 2);
    d = (sqrt(ans)) / 2.0;
    cc[ID(1)] = 1 , cc[ID(2)] = 2;
    REP(i , 3 , n + 1){
        int id = ID(i);
        int a = id / N , b = id % N , dis = ans;
        REP(ii , -2 , 2 + 1) REP(jj , -2 , 2 + 1){
            int aa = a + ii , bb = b + jj;
            if(cc.find(aa * N + bb) != cc.end())
                dis = min(dis , DIS(cc[aa * N + bb] , i));
        }
        if(dis < ans){
            ans = dis , d = (sqrt(ans)) / 2.0;
            cc.clear();
            REP(j , 1 , i + 1) cc[ID(j)] = j;
        }
        else cc[id] = i;
    }
    return ans;
}
int32_t main(){
    IOS;
    srand(time(NULL));
    cin >> n;
    REP(i , 1 , n + 1) cin >> pre[i] , pre[i] += pre[i - 1];
    REP(i , 1 , n + 1) p[i][0] = i , p[i][1] = pre[i];
    random_shuffle(p + 1 , p + 1 + n);
    int ans = solve();
    cout << ans << endl;
    return 0;
}