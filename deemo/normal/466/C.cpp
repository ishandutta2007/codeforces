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
const ll max_n = 1e6;
ll n , temp , sum , par[max_n] , c[max_n] , cnt , ans;

int main(){
    cin >> n;
    for (ll i = 0 ; i < n ; i++){
	 cin >> temp;
	 sum += temp;
	 if (i == 0) par[i] = temp;
	 else	  par[i] = par[i - 1] + temp;
    }	 

    if (sum % 3 != 0){
	 cout << 0 << endl;
	 return  0;
    }

    for (int i = 0 ; i < n ; i++){
	 if (i == 0 && par[i] == sum / 3)	  c[i] = 1;
	 else	  if (i != 0 && par[i] == sum / 3)	   c[i] = c[i - 1] + 1;
	 else	  c[i] = c[i - 1];
    }
    for (int i = 1 ; i < n - 1 ; i++)
	 if (par[i] == 2 * (sum / 3))    ans += c[i - 1];
    cout << ans << endl;
    return 0;
}