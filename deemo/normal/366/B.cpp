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

ll maxi = 1e9;
ll n , k , ind;
vector<ll> vec;
const ll max_n = 1e5 + 200;
bool mark[max_n];

int main(){
    cin >> n >> k;
    ll temp;
    for (ll i = 0 ; i < n ; i++){
	 cin >> temp;
	 vec.push_back(temp);
    }

    for (ll i = 0 ; i < n ; i++){
	 if (mark[i] != 0)	continue;
	 mark[i] = 1;
	 ll z = i , c = vec[i];
	 z = (z + k) % n;
	 while (z != i){
	     mark[z] = 1;
	     c += vec[z];
	     z = (z + k) % n;
	 }
	 if (c < maxi){
	     maxi = c;
	     ind = i;
	 }
    }
    cout << ind + 1 << endl;
    return 0;
}