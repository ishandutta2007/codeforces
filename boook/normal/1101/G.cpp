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
#define int long long
#define MAX 200009
#define INF 0x3f3f3f3f

int n , x[MAX];

int las = 0;
vector<int> pre , now;
void check(){
    int tmp = 0;
    REP(i , 1 , n + 1) tmp ^= x[i];
    if(tmp == 0){
        cout << -1 << endl;
        exit(0);
    }
}
int32_t main(){
    IOS;
    cin >> n;
    REP(i , 1 , n + 1) cin >> x[i];
    check();
    int frontisgood = 1;
    REP(i , 1 , n + 1){
        int val = x[i];
        for(auto to : now) val = min(val , to ^ val);
        if(val != 0 && frontisgood == 1){
            las = x[i];
            pre = now;
            now.push_back(val);
        }
        else {
            las = las ^ val , val = las;
            now = pre;
            for(auto to : pre) val = min(val , to ^ val);
            if(val != 0){
                frontisgood = 1;
                now = pre;
                now.push_back(val);
            }
            else {
                frontisgood = 0;
            }
        }  
    }
    cout << now.size() << endl;
    return 0;
}