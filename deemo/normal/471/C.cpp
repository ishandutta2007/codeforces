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
ll n;
const int max_m = 1e6;
ll ans;

int main(){
    cin >> n;
    for (int i = 1 ; i <= max_m ; i++){
	 ll t = ll(n + i);
	 if (t % 3 != 0) continue;
	 t /= 3;
	 ll temp = (long long)(i * ll(i + 1) / 2);
	 if (temp <= t)   ans++;
    }
    cout << ans << endl;
    return 0;
}