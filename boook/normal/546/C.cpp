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
#define MAX 
#define INF 0x3f3f3f3f


set<pair<queue<int> , queue<int>>> cc;

int n;
queue<int> a , b;
int32_t main(){
    IOS;
    cin >> n;

    int tmp , res; cin >> tmp;
    REP(i , 0 , tmp){
        cin >> res;
        a.push(res);
    }
    cin >> tmp;
    REP(i , 0 , tmp){
        cin >> res;
        b.push(res);
    }
    int cnt = 0;
    while(cc.find(mp(a , b)) == cc.end()){
        cnt ++;
        cc.insert(mp(a , b));
        int q = a.front() , w = b.front();
        a.pop() , b.pop();
        if(q > w) a.push(w) , a.push(q);
        if(q < w) b.push(q) , b.push(w);
        if(a.size() == 0 || b.size() == 0){
            if(a.size() == 0) cout << cnt << " 2" << endl;
            if(b.size() == 0) cout << cnt << " 1" << endl;  
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}