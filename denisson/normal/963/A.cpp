#include <bits/stdc++.h>
  
using namespace std;
  
typedef long long ll;
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

const int mod = (int)1e9 + 9;
string s;
int n, a, b, k;

int bp(int a, int k){
	if (k == 0) return 1;
	if (k % 2 == 1){
		return a * (ll)bp(a, k - 1) % mod;
	} else {
		int q = bp(a, k / 2);
		return q * (ll)q % mod;
	}
}

int main(){
   // freopen("input.txt", "r", stdin);
    //freopen("output1.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> a >> b >> k >> s;
    int ans = 0;

    for (int i = 0; i < s.size(); i++){
    	int val = 1;
    	if (s[i] == '-') val = mod - 1;
    	val = (val * (ll)bp(b, i)) % mod;
    	val = (val * (ll)bp(a, n - i)) % mod;
    	ans = (ans + (ll)val) % mod;
    }


    int cnt = (n + 1) / k;

    int gg = bp(b, k) * (ll)bp(bp(a, k), mod - 2) % mod;
    //cout << ans << ' ' << cnt << ' ' << gg << endl;

    if (gg == 1){
    	ans = ans * (ll)cnt % mod;
    } else {
    	ll tmp = ans * (ll)(mod + 1 - bp(gg, cnt)) % mod;
    	tmp = tmp * (ll)bp((mod + 1 - gg), mod - 2) % mod;
    	ans = tmp;
    }

    cout << ans;
}