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

using namespace std;

typedef long long ll;
const ll max_n = 2000 + 20;
ll n;
double m;
ll x[max_n] , y[max_n];
const ll q = 500;
long long ans;
map<pair<ll , double> , ll> mp;
vector<double> vec[max_n];

ll get(ll x){
    if (x < 2)  return  0;
    return  x * (x - 1) / 2;
}

int main(){
    cin >> n;
    for (ll i = 0 ; i < n ; i++)
	 cin >> x[i] >> y[i];
    for (ll i = 0 ; i < n ; i++)
	 for (ll j = i - 1 ; j >= 0 ; j--){
	     if (x[i] == x[j])   m = q;
	     else    m = double(y[i] - y[j]) / double(x[i] - x[j]);
	     vec[i].push_back(m);
	     mp[{i , m}] += 1;
	 }

    long long t = 0;
    for (ll i = 2 ; i < n ; i++){
	 for (ll j = 0 ; j < vec[i].size() ; j++){
	     t += get(mp[{i , vec[i][j]}]);
	     mp[{i , vec[i][j]}] = 0;
	 }
    }
    if (n >= 3) ans = (long long)(n * (n - 1) * (n - 2)) / 6;
    ans -= t;
    cout << ans << endl;
    return 0;
}