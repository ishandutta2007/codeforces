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
ll n , k , l , m , ans = 1 , q = 1 , z;
map<ll , ll>	  d;
map<ll , ll>	  p;
map<ll , bool>  mark;
map<ll , bool>  mark2;

ll c(ll x){
    if (x % 2 == 0) return	ll(x / 2);
    else    return  ll(ll(x / 2) + 1);
}

ll p2(ll x){
    if (x == 0) return  1;
    if (x == 1) return  2;
    
    if (mark[x] != 0)  return	p[x];
    mark[x] = 1;
    return  p[x] = ll(p2(ll(x/2)) * p2(c(x))) % m;
}

ll get(ll x){
    if (x == 1) return  1;
    if (x == 2) return  2;
    if (x == 3) return  3;
    if (x == 4) return  5;

    if (mark2[x] != 0)  return	d[x];
    mark2[x] = 1;
    if (x % 2 == 0) return	d[x] = ll(ll(get(x / 2) * get(x / 2)) + ll(get(x/2 - 1) * get(x/2 - 1))) % m;
    return  d[x] = ll(ll(get(x/2) * get(x/2 + 1)) + ll(get(x/2 - 1) * get(x/2))) % m;
}

void get(){
    bool b;
    for (int i = 0 ; i < l ; i++){
	 b = (k & 1);
	 k >>= 1;
	 if (b == 0) ans = ll(ans * z) % m;
	 else	  ans = ll(ans * ll((q + m) - z)) % m;
    }
}

int main(){
    cin >> n >> k >> l >> m;
    if (l == 0){
	 if (k == 0) ans = 1;
	 else	  ans = 0;
	 cout << ans % m << endl;
	 return  0;
    }
    if (log2(k) >= l){
	 cout << 0 << endl;
	 return  0;
    }

    q = p2(n);
    z = get(n + 1);

    get();
    cout << ans % m << endl;
    return 0;
}