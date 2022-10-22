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
#include<cstring>
#include<bitset>
#include<functional>

using namespace std;

typedef long long ll;
//#define size(x) ((ll)(x).size())
#define error(x) cerr << #x << " = " << x << endl
#define pb push_back
#define setprecision(x) cout << fixed << setprecision((x))
#define read_fast ios_base::sync_with_stdio(false) , cin.tie(0)
#define PQ priority_queue;

ll n , k;
const ll max_n = 3e5;
ll ans;
map<ll , ll>	  dp[4];

int main(){
    read_fast;
    cin >> n >> k;
    ll temp;
    for (ll i = 0 ; i < n ; i++){
	 cin >> temp;
	 if (temp % k != 0)
	     dp[0][temp] += 1;
	 else{
	     ll t = temp / k;
	     ans -= dp[2][temp];
	     if (t % k == 0)	dp[2][temp] += dp[1][t];
	     dp[1][temp] += dp[0][temp / k];
	     dp[0][temp] += 1;
	     ans += dp[2][temp];
	 }
    }
    cout << ans << endl;
    return 0;
}