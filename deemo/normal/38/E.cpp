/*
    I found myself in Wonderland
    Get back on my feet again..
*/

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
#include<numeric>

using namespace std;

typedef long long ll;
//#define size(x) ((ll)(x).size())
#define error(x) cerr << #x << " = " << x << endl
#define pb push_back
#define setprecision(x) cout << fixed << setprecision((x))
#define read_fast ios_base::sync_with_stdio(false) , cin.tie(0)
#define PQ priority_queue;

ll n;
vector<pair<ll , ll>>  vec;
const ll max_n = 5000;
ll d[max_n];

int main(){
    read_fast;
    cin >> n;
    {
	 ll a , b;
	 for (ll i = 0 ; i < n ; i++){
	     cin >> a >> b;
	     vec.push_back({a , b});
	 }
	 sort(vec.begin() , vec.end());
    }
    d[0] = vec[0].second;
    for (ll i = 1 ; i < n ; i++){
	 ll mini = vec[i].second + d[i - 1];
	 ll w = vec[i].first - vec[i - 1].first;
	 for (ll j = i - 1 ; j >= 0 ; j--){
	     ll t;
	     if (j != 0) t = w + vec[j].second + d[j - 1];
	     else    t = w + vec[j].second;
	     mini = min(mini , t);
	     w += (i - j + 1) * (vec[j].first - vec[j - 1].first);
	 }
	 d[i] = mini;
    }
    cout << d[n - 1] << endl;
    return 0;
}