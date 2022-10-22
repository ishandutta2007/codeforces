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
vector<ll> vec , gec;
ll ans , n , s , l;

ll cnt(ll x){
    ll ret = 0;
    while (x > 0){
	 if (x & 1)  ret++;
	 x >>= 1;
    }
    return  ret;
}

ll get(ll x , ll o){
    ll z = s - 1 + (n - o);
    ll p = x;
    for (ll i = 0 ; i < n ; i++){
	 if (x & 1)  z -= vec[i];
	 if (z < 0)  return	0;
	 x >>= 1;
    }
    
    if (z < n - 1)  return	0;
    if (z == n - 1 || z == 0) return	1;
    
    vector<ll> sec , hec;
    for (ll i = z ; ll(z - i) < (n - 1) ; i--)
	 sec.push_back(i);
	 
    hec.assign(gec.begin() , gec.end());
    while (hec.size() != 0)
	 for (int j = 0 ; j < sec.size() ; j++)
	     if (sec[j] % hec[hec.size() - 1] == 0){
		  sec[j] /= hec[hec.size() - 1];
		  hec.pop_back();
		  j++;
		  if (hec.size() == 0)    break;
	     }

    ll ret = 1;
    for (ll i = 0 ; i < sec.size() ; i++){
	 ret *= (sec[i] % q);
	 ret %= q;
    }
    return  ret;
}

int main(){
    cin >> n >> s;
    ll temp;
    l = 1;
    for (ll i = 0 ; i < n ; i++){
	 cin >> temp;
	 vec.push_back(temp);
    }

    for (int i = 1 ; i <= n - 1 ; i++)
	 l *= i;

    for (int i = 2 ; i <= n - 1 ; i++){
	 while (l % i == 0){
	     l /= i;
	     gec.push_back(i);
	 }
    }

    ll z = 1;
    for (ll i = 0 ; i < n ; i++)
	 z <<= 1;

    for (ll i = 0 ; i < z ; i++){
	 ll temp = cnt(i);
	 if (temp % 2 == 0)	ans = ll(ans + get(i , temp)) % q;
	 else	  ans = (ans + q - get(i , temp)) % q;
    }
    cout << ans << endl;

    return 0;
}