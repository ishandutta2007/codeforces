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
#define IOS cin.tie() , cout.sync_with_stdio(0)
///------------------------------------------------------------
#define int long long
#define MAX 100000
#define INF 0x3f3f3f3f


int n , k , x[MAX];
map<int , int> cc;

int32_t main(){
    IOS;
    cin >> n >> k;
    REP(i , n) cin >> x[i];
    REP(i , n) cc[x[i] - k * i] = 0;
    REP(i , n) cc[x[i] - k * i] ++;
    PII mm = mp(cc[x[0]] , 0);
    REP(i , n){
        if(cc[x[i] - k * i] > mm.A && x[i] - k * i > 0) mm = mp(cc[x[i] - k * i] , i);
    }
    int to = x[mm.B] - k * mm.B , cnt = 0;
    REP(i , n){
        if(x[i] - k * i != to) cnt ++;
    }
    cout << cnt << "\n";
    REP(i , n){
        if(x[i] - k * i != to){
            int goal = to + k * i - x[i];
            if(goal > 0) cout << "+ " << i + 1 << " " << goal << "\n";
            if(goal < 0) cout << "- " << i + 1 << " " << -goal << "\n";
        }
    }
    return 0;
}