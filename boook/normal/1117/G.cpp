/*input
20 20
16 7 2 14 11 19 9 6 20 12 3 13 5 17 10 8 4 18 15 1
1 1 1 1 1 1 1 1 1  1  1  1  1  1  1  1  1  1  1  1
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i, j, k)  for(int i = j; i <  k; ++i)
#define RREP(i, j, k) for(int i = j; i >= k; --i)
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define PII pair<int , int>
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 1000090
#define INF 0x3f3f3f3f

long long bit[3][MAX];
void modify(int type , int idx , int val){
    for(int i = idx ; i < MAX ; i += i & -i)
        bit[type][i] += val;
}
void update(int type , int ql , int qr , int val){
    modify(type , ql + 0 , val);
    modify(type , qr + 1 , -val);
}
long long query(int idx , int yy){
    long long cnt = 0;
    for(int i = idx ; i > 0 ; i -= i & -i)
        cnt += 1ll * bit[0][i] * idx + bit[1][i] + bit[2][i] * yy;
    return cnt;
}

struct Node{
    int lx , ly , add , adi , adj;
};

int n , m , ql[MAX] , qr[MAX] , x[MAX];
long long ans[MAX];
int l[MAX] , r[MAX];
int L(int idx , int val){ return x[idx] > val ? idx : L(l[idx] , val); }
int R(int idx , int val){ return x[idx] > val ? idx : R(r[idx] , val); }
vector<Node> sol[MAX];
vector<int> quy[MAX];
int32_t main(){
    IOS;
    cin >> n >> m;
    REP(i , 1 , n + 1) cin >> x[i];
    REP(i , 1 , m + 1) cin >> ql[i];
    REP(i , 1 , m + 1) cin >> qr[i];

    x[0] = n + 1 , x[n + 1] = n + 2;
    REP(i , 1 , n + 1) l[i] = L(i - 1 , x[i]);
    RREP(i , n , 1)    r[i] = R(i + 1 , x[i]);

    // REP(i , 1 , n + 1) cout << l[i] << " "; cout << endl;
    // REP(i , 1 , n + 1) cout << r[i] << " "; cout << endl;

    REP(i , 1 , m + 1) quy[qr[i]].pb(i); 

    REP(i , 1 , n + 1){
        int lth = l[i] , rth = r[i];
        int len = (rth - 1) - (lth + 1) + 1;
        // int lx , ly , rx , ry , add , adi , adj;

        sol[  i].pb(Node{lth + 1 ,   i ,               1 , -1 , 1});
        sol[  i].pb(Node{      1 , lth ,  -(lth + 1) + 1 ,  0 , 1});

        sol[rth].pb(Node{      1 , lth ,   lth + len ,  0 , -1});
        sol[rth].pb(Node{lth + 1 ,   i ,   rth - 1 ,  0 , -1});




        // sol[rth].pb(Node{      1 , lth ,             len ,  0 , 0});
        // sol[n+1].pb(Node{      1 , lth ,            -len ,  0 , 0});

        // sol[  i].pb(Node{lth + 1 ,   i ,               1 , -1 , 1});
        // sol[rth].pb(Node{lth + 1 ,   i ,              -1 ,  1 ,-1});

        // sol[  i].pb(Node{      1 , lth ,  -(lth + 1) + 1 ,  0 , 1});
        // sol[rth].pb(Node{      1 , lth ,   (lth + 1) - 1 ,  0 ,-1});

        // sol[rth].pb(Node{lth + 1 ,   i ,   (rth - 1) + 1 , -1 , 0});
        // sol[n+1].pb(Node{lth + 1 ,   i ,  -(rth - 1) - 1 ,  1 , 0});

    }
    REP(i , 1 , n + 1){
        for(auto val : sol[i]){
            // printf("lx = %d ly = %d rx = %d ry = %d add = %d adi = %d adj = %d\n", 
            //     val.lx , val.ly , val.rx , val.ry , val.add , val.adi , val.adj);
            update(0 , val.lx , val.ly , val.adi);
            update(1 , val.lx , val.ly , val.add);
            update(2 , val.lx , val.ly , val.adj);
            // if(val.ly == 0) break;
        }
        for(auto idx : quy[i]) ans[idx] = query(ql[idx] , i);
        // break;
    }
    REP(i , 1 , m + 1) cout << ans[i] << " "; cout << endl;
    // focus none segment
    return 0;
}