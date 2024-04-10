#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j)       for(int i = 0 ; i < j ; i++)
#define REPNM(i,j,k)   for(int i = j ; i < k ; i++)
#define RREP(i,j,k)    for(int i = j ; i >=k ; i--)
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
#define RI(i)       scanf("%d" , &i)
#define RII(i,j)    scanf("%d%d" , &i , &j)
#define RIII(i,j,k) scanf("%d%d%d" , &i , &j , &k)
#define RL(i)       scanf("%lld" , &i)
#define RLL(i,j)    scanf("%lld%lld" , &i , &j)
#define RLLL(i,j,k) scanf("%lld%lld%lld" , &i , &j , &k)
#define AS assert
#define IOS cin.tie() , cout.sync_with_stdio(0)
///------------------------------------------------------------
#define MAX 300900
#define INF 0x3f3f3f3f
#define mid ((l + r) / 2)
#define ls (now << 1)
#define rs (now << 1 | 1)
string s;
int n , m;
int cnt[MAX * 4] , sum[MAX * 4];
void Pull(int now , int l , int r){
    sum[now] = sum[ls] + sum[rs];
    cnt[now] = cnt[ls] + cnt[rs];
    if(s[mid] == '.' && s[mid + 1] == '.') cnt[now] --;
}
void Build(int now , int l , int r){
    if(l == r){
        if(s[l] == '.') cnt[now] = 1 , sum[now] = 1;
        else cnt[now] = 0 , sum[now] = 0;
        return ;
    }
    Build(ls , l , mid);
    Build(rs , mid + 1 , r);
    Pull(now , l , r);
}
void update(int now , int l , int r , int k){
    if(l == k && r == k){
        if(s[l] == '.') cnt[now] = 1 , sum[now] = 1;
        else cnt[now] = 0 , sum[now] = 0;
        return ;
    }
    else if(k <= mid) update(ls , l , mid , k);
    else update(rs , mid + 1 , r , k);
    Pull(now , l , r);
}
int32_t main(){
    IOS;
    cin >> n >> m >> s;
    Build(1 , 0 , s.size() - 1);
    REP(i , m){
        int q;
        char w;
        cin >> q >> w;
        s[q - 1] = w;
        update(1 , 0 , s.size() - 1 , q - 1);
        cout << sum[1] - cnt[1] << "\n";
    }
    return 0;
}