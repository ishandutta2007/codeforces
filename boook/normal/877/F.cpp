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
#define MAX 100900
#define N 317

int n , m , k , ty[MAX] , x[MAX] , q[MAX][2];
long long pre[MAX] , ans[MAX];
int sol[MAX] , cc[400900];
long long val[MAX] , add[MAX] , sub[MAX];
void solve(){
    int l = 1 , r = 0;
    long long res = 0;
    REP(i , 1 , k + 1){
        int ql = q[sol[i]][0] - 1;
        int qr = q[sol[i]][1];
        while(ql < l){
            l --;
            res += cc[add[l]];
            cc[pre[l]] ++;
        }
        while(r < qr){
            r ++;
            res += cc[sub[r]];
            cc[pre[r]] ++;
        }
        while(l < ql){
            cc[pre[l]] --;
            res -= cc[add[l]];
            l ++;
        }
        while(qr < r){
            cc[pre[r]] --;
            res -= cc[sub[r]];
            r --;
        }
        ans[sol[i]] = res;
    }
}
int cmp(int a , int b){
    if(q[a][0] / N != q[b][0] / N) return q[a][0] < q[b][0];
    else return q[a][1] < q[b][1];
}
vector<long long> uni;
inline long long rit(){
    char c = getchar();
    long long tmp = 1 , res = 0;
    while(!isdigit(c)){
        if(c == '-') tmp = -1;
        c = getchar();
    }
    while(isdigit(c)){
        res = (res << 1) + (res << 3) + c - '0';
        c = getchar();
    }
    return res * tmp;
}
int32_t main(){
    n = rit() , m = rit();
    REP(i , 1 , n + 1) ty[i] = rit();
    REP(i , 1 , n + 1) x[i] = rit();
    REP(i , 1 , n + 1) if(ty[i] == 2) x[i] *= -1;

    REP(i , 1 , n + 1) pre[i] = pre[i - 1] + x[i];

    REP(i , 0 , n + 1){
        uni.pb(pre[i]);
        add[i] = pre[i] + m;
        uni.pb(pre[i] + m);
        sub[i] = pre[i] - m;
        uni.pb(pre[i] - m);
    }
    
    sort(ALL(uni));
    uni.resize(unique(ALL(uni)) - uni.begin());
    REP(i , 0 , n + 1) pre[i] = lower_bound(ALL(uni) , pre[i]) - uni.begin();
    REP(i , 0 , n + 1) add[i] = lower_bound(ALL(uni) , add[i]) - uni.begin();
    REP(i , 0 , n + 1) sub[i] = lower_bound(ALL(uni) , sub[i]) - uni.begin();

    k = rit();
    REP(i , 1 , k + 1) q[i][0] = rit() , q[i][1] = rit();
    REP(i , 1 , k + 1) sol[i] = i;
    sort(sol + 1 , sol + 1 + k , cmp);
    
    solve();
    REP(i , 1 , k + 1) printf("%lld\n" , ans[i]);
    return 0;
}