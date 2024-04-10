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
#define MAX 200000
#define INF 0x3f3f3f3f
#define RG 1000000090LL
#define mid (l + (r - l) / 2)

int n;
int tag[MAX * 20] , siz[MAX * 20];
int ls[MAX * 20] , rs[MAX * 20];
int po = 2;
void update(int now , int l , int r , int ql , int qr , int k){
    if(ql <= l && r <= qr) tag[now] += k;
    else{
        if(ls[now] == 0) ls[now] = po ++;
        if(rs[now] == 0) rs[now] = po ++;
        if(qr <= mid) update(ls[now] , l , mid , ql , qr , k);
        else if(mid + 1 <= ql) update(rs[now] , mid + 1 , r , ql , qr , k);
        else {
            update(ls[now] , l , mid , ql , qr , k);
            update(rs[now] , mid + 1 , r , ql , qr , k);
        }
        siz[now] = 0;
        if(tag[ls[now]] != 0) siz[now] += (mid - l + 1);
        else siz[now] += siz[ls[now]];
        if(tag[rs[now]] != 0) siz[now] += (r - (mid + 1) + 1);
        else siz[now] += siz[rs[now]];
    }
}
vector<pair<PII , PII> > sol; 
int32_t main(){
    cin >> n;
    REP(i , 0 , n){
        int q , w , e , r;
        cin >> q >> w >> e >> r;
        if(w == r){
            if(q > e) swap(q , e);
            sol.pb(mp(mp(w , 1) , mp(q , e)));
            sol.pb(mp(mp(r + 1 , -1) , mp(q , e)));
        }
        else {
            if(w > r) swap(w , r);
            sol.pb(mp(mp(w , 1) , mp(q , e)));
            sol.pb(mp(mp(r + 1 , -1) , mp(q , e)));
        }
    }
    sort(ALL(sol));
    int lat = sol[0].A.A , ans = 0;
    // DBGG("------" , "======");
    REP(i , 0 , sol.size()){
        PII now = sol[i].A;
        PII lr = sol[i].B;
        ans += siz[1] * (now.A - lat) , lat = now.A;

        // DB4(ans , siz[1] , now.A , lat);
        update(1 , -RG , RG , lr.A , lr.B , now.B);


        // DB4("modify = " , lr.A , lr.B , now.B);
        // DBGG("finish siz[1] = " , siz[1]);

    }
    cout << ans << endl;
    return 0;
}