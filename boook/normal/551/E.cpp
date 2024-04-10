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
#define endl '\n'
///------------------------------------------------------------
typedef long long LL;
#define MAX 500900
#define INF 1000000010LL

int n , m , N;
LL x[MAX] , add[MAX];
set<pair<LL , int>> cc[MAX / 10];
void update(int l , int r , LL val){
    while(l <= r){
        if(l % N == 0 && l + N - 1 <= r) add[l / N] += val , l += N;
        else {
            cc[l / N].erase(mp(x[l] , l));
            x[l] += val;
            if(x[l] + add[l / N] < INF) cc[l / N].insert(mp(x[l] , l));
            l ++;
        }
    }
}
int query(LL vv){
    int sml = n + 10 , big = 0 , ql = 0 , qr = n / N + 1;
    while(ql <= qr){
        LL val = vv - add[ql];
        if(vv < add[ql]){
            ql ++;
            continue;
        }
        auto ss = cc[ql].lower_bound(mp(val , 0));
        if(ss != cc[ql].end() && (*ss).A == val){
            sml = min(sml , (*ss).B);
            break;
        }
        ql ++;
    }
    while(ql <= qr){
        LL val = vv - add[qr];
        if(vv < add[qr]){
            qr--;
            continue;
        }
        auto bb = cc[qr].upper_bound(mp(val , n + 10));
        if(bb != cc[qr].begin()){
            bb --;
            if((*bb).A == val){
                big = max(big , (*bb).B);
                break;
            }
        }
        qr--;
    }
    if(big == 0) return -1;
    else return big - sml;
}
int32_t main(){
    IOS;
    cin >> n >> m;
    N = sqrt(n * log2(n));
    N = max(1 , N);
    REP(i , 1 , n + 1){
        cin >> x[i];
        cc[i / N].insert(mp(x[i] , i));
    }
    int q , w , e;
    REP(i , 1 , m + 1){
        cin >> q;
        if(q == 1){
            cin >> q >> w >> e;
            update(q , w , e);
        }
        else if(q == 2){
            cin >> q;
            cout << query(q) << endl;
        }
    }
    return 0;
}