#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j)       for(int i = 0 ; i < j ; ++i)
#define REPNM(i,j,k)   for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
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
#define MAX 100900
#define INF 0x3f3f3f3f
#define mid ((l + r) >> 1)
#define ls (now << 1)
#define rs (now << 1 | 1)
#define MM 18
typedef long long LL;

int n , m , x[MAX];
int bl[MM][MAX * 4] , br[MM][MAX * 4];
LL sum[MM][MAX * 4];
LL C(LL now){ return now * (now + 1) / 2; }
void update(int ty , int now , int l , int r , int k , int val){
    if(l == k && r == k){
        bl[ty][now] = br[ty][now] = val;
        sum[ty][now] = 0;
        return ;
    }
    if(k <= mid) update(ty , ls , l , mid , k , val);
    if(mid + 1 <= k) update(ty , rs , mid + 1 , r , k , val);
    int brl = 0 , brr = 0;
    int lsum = mid - l + 1 , rsum = r - (mid + 1) + 1;
    if(br[ty][ls] == lsum) brl = 1;
    if(bl[ty][rs] == rsum) brr = 1;
    if(brl && brr){
        bl[ty][now] = br[ty][now] = r - l + 1;
        sum[ty][now] = 0;
    }
    else if(brl == 1){
        bl[ty][now] = bl[ty][rs] + lsum;
        br[ty][now] = br[ty][rs];
        sum[ty][now] = sum[ty][rs];
    }
    else if(brr == 1){
        br[ty][now] = br[ty][ls] + rsum;
        bl[ty][now] = bl[ty][ls];
        sum[ty][now] = sum[ty][ls];
    }
    else {
        br[ty][now] = br[ty][rs];
        bl[ty][now] = bl[ty][ls];
        sum[ty][now] = sum[ty][ls] + sum[ty][rs] + C(br[ty][ls] + bl[ty][rs]);
    }
}
void modify(int a , int b){
    bitset<MM> tmp(b);

    // REP(i , MM) cout << tmp[i] << " " ; cout << endl;
    REP(i , MM) update(i , 1 , 1 , n , a , tmp[i]);
}
LL query(){
    LL ans = 0;
    REP(i , MM){
        LL tmp;
        if(bl[i][1] != n) tmp = (LL(sum[i][1]) + C(LL(bl[i][1])) + C(LL(br[i][1])));
        else tmp = C(n);
        ans += tmp * (1LL << i);
        // DBGG("tmp = " , tmp * (1LL << i));
    }
    return ans;
}
int32_t main(){
    IOS;
    cin >> n >> m;
    REP(i , n) cin >> x[i] , modify(i + 1 , x[i]);
    REP(i , m){
        int q , w;
        cin >> q >> w;
        modify(q , w);
        cout << query() << "\n";
    }
    return 0;
}