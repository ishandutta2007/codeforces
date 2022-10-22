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
ll n , h;
ll ans , g;

ll f(ll x){
    ll ret = 1;
    for (ll i = 0 ; i < x ; i++)
	 ret *= 2;
    return  ret;
}

ll get(ll a , ll b , ll c , ll d , int t){//0 -> chap
    if (c != 1 || f(h) != d)    g /= 2;
    //if (c > d) return  0;
    if (a == 0) return  0;
    ll mid = ll(ll(c + d) / 2);
    if (b <= mid){
	 if (t == 0) return	ll(1 + get(a - 1 , b , c , mid , 1));
	 return  ll(1 + ll(g/2) + get(a - 1 , b , c , mid , 1));
    }
    if (t == 0)
	 return  ll(1 + ll(g / 2) + get(a - 1 , b , mid + 1 , d , 0));
    return  ll(1 + get(a - 1 , b , mid + 1 , d , 0));
}

int main(){
    cin >> h >> n;
    g = f(h + 1);
    g -= 1;
    ans = get(h , n , 1 , f(h) , 0);
    cout << ans << endl;
    return 0;
}