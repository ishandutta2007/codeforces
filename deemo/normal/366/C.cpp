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

const ll z = 1e5 + 500 , q = 1e9;
ll n , k;
const ll max_n = 200;
ll a[200] , b[200];
vector<ll> vec;
ll arr[5 * z] , barr[5 * z];

int main(){
    cin >> n >> k;
    for (ll i = 0 ; i < n ; i++)
	 cin >> a[i];
    for (ll i = 0 ; i < n ; i++){
	 cin >> b[i];
	 b[i] *= k;
    }
    for (ll i = 0 ; i < n ; i++)
	 vec.push_back(a[i] - b[i]);
    for (ll i = 0 ; i < 5 * z ; i++)
	 arr[i] = q;
    
    arr[0 + z] = 0;

    for (ll i = 0 ; i < vec.size() ; i++){
	 ll temp = vec[i];
	 for (ll j = -(1e5) ; j <= 1e5 ; j++){
	     if (j + temp + z < 0 || j + temp + z >= 5 * z)  continue;
	     if (arr[j + z] == q){
		  barr[j + temp + z] = arr[j + temp + z];
		  continue;
	     }
	     //if (i == 1) cout << j << endl;
	     int t = arr[j + temp + z];
	     if (arr[j + temp + z] == q)	  arr[j + temp + z] = 0;
	     arr[j + temp + z] = max(arr[j + temp + z] , arr[j + z] + a[i]);
	     barr[j + temp + z] = arr[j + temp + z];
	     arr[j + temp + z] = t;
	 }

	 for (ll j = -(1e5) ; j <= 1e5 ; j++)
	     arr[j + z] = barr[j + z];

    }
    if (arr[0 + z] == 0)	   cout << -1 << endl;
    else    cout << arr[0 + z] << endl;
    return 0;
}