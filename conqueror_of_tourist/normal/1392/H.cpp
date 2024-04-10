#include <iostream> 
#include <algorithm> 
using namespace std;
 
typedef long long ll;
 
ll MOD = 998244353;

ll power(ll x, ll y, ll p)  
{  
    ll res = 1;     // Initialize result  
  
    x = x % p; // Update x if it is more than or  
                // equal to p 
   
    if (x == 0) return 0; // In case x is divisible by p; 
  
    while (y > 0)  
    {  
        // If y is odd, multiply x with result  
        if (y & 1)  
            res = (res*x) % p;  
  
        // y must be even now  
        y = y>>1; // y = y/2  
        x = (x*x) % p;  
    }  
    return res;  
}

ll inv(ll x){
	return power(x, MOD - 2, MOD);
}

int main() {
  ll n;
  ll m;
  cin >> n >> m;
  
  ll mult = inv(m + 1);
  mult *= n;
  mult += 1;
  mult %= MOD;
  
  ll out = m + 1;
  for (int i = 2; i <= n; i++){
    ll add = m * inv(i);
    add %= MOD;
    out += add;
    out %= MOD;
  }
  
  out *= mult;
  out %= MOD;
  cout << out << endl;
  return 0;
}