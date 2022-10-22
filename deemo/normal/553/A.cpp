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
const ll q = 1e9 + 7;
ll ans , k;
const ll maxi = 1100;
ll d[maxi][maxi];
vector<ll> vec;
ll p[maxi];

ll cal(ll x){
    if (x == 1) return  1;
    ll ret = cal(x - 1);
    ll t = vec[x] - 1;
    t = d[p[x - 1] + t][t];
    ret = ll(ret * t) % q;
    return  ret;
}

void init(){
    d[0][0] = 1;
    for (ll i = 1 ; i < maxi ; i++){
	 d[i][0] = d[i][i] = 1;
	 for (ll j = 1 ; j < i ; j++)
	     d[i][j] = ll(d[i - 1][j] + d[i - 1][j - 1]) % q;
    }
}

int main(){
    cin >> k;
    ll temp;
    vec.push_back(0);
    for (ll i = 1 ; i <= k ; i++){
	 cin >> temp;
	 vec.push_back(temp);
	 if (i == 0) p[i] = temp;
	 else	  p[i] = p[i - 1] + temp;
    }
    init();
    ans = cal(k);
    cout << ans << endl;
    return 0;
}