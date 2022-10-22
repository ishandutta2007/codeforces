#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<string>
#include<utility>
#include<iomanip>
#include<fstream>
#include<list>
#include<sstream> 

using namespace std;

typedef long long ll;
//#define size(x) ((int)(x).size())
#define error(x) cerr << #x << " = " << x << endl
//#define push_back pb
#define setprecision(x) cout << fixed << setprecision((x))
#define read_fast ios_base::sync_with_stdio(false) , cin.tie(0)

vector<pair<int , int>> vec;
int n , h , w;
const int q = 1e9 + 7;
const int MAXI = 2e5 + 100;
ll d[MAXI] , c[MAXI] , dp[MAXI];

bool help(pair<int , int>a , pair<int , int> b){
    if (a.second < b.second)    return  true;
    if (a.second == b.second && a.first < b.first)  return  true;
    return  false;
}

ll tavan(int a , int b){
    if (b == 0) return  1;
    if (b == 1) return  a;
    if (b % 2 == 0){
        ll ret = tavan(a , b / 2);
        ret *= ret;
        return  ret % q;
    }
    ll ret = tavan(a , b/2);
    ret *= ret;
    ret %= q;
    ret *= a;
    return  ret % q;
}

void init(){
    ll t = 1;
    for (int i = 1 ; i <= MAXI ; i++){
        //if (vec.size() > 3)    cout << i << endl;
        t *= i;
        t %= q;
        c[i] = t;
        d[i] = tavan(t , q - 2);
    }
}

ll cal(int a , int b){
    if (a == 0 || b == 0)   return  1;
    a += b;
    ll ret = c[a];
    ret *= d[a - b];
    ret %= q;
    ret *= d[b];
    return  ret % q;
}

void solve(){
    for (int i = 0 ; i < vec.size() ; i++) {
        ll sum = 0;
        for (int j = 0 ; j < i ; j++) {
            if (vec[j].first > vec[i].first)    continue;
            ll temp = dp[j];
            temp *= cal(vec[i].first - vec[j].first , vec[i].second - vec[j].second);
            temp %= q;
            sum = (sum + temp) % q;
        }
        dp[i] = cal(vec[i].first - 1 , vec[i].second - 1);
        dp[i] = (dp[i] + q - sum) % q;
    }
}

int main(){
    read_fast;
    cin >> h >> w >> n;
    int a , b;
    for (int i = 0 ; i < n ; i++){
        cin >> a >> b;
        vec.push_back({a , b});
    }
    sort(vec.begin() , vec.end() , help);
    vec.push_back({h , w});
    init();
    solve();
    cout << dp[n] << endl;
    return 0;
}