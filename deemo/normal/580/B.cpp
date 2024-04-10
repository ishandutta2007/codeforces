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
#define to_string(x) ({ string _str; stringstream _ss; _ss << x;  _ss >> _str; _str; })
#define to_ll(x) ({ ll _x; stringstream _ss; _ss << x; _ss >> _x; _x; })

ll n, d;
deque<pair<ll, ll>>	saf;
vector<pair<ll, ll>>	vec;

int main(){
	read_fast;
	cin >> n >> d;
	vec.resize(n);
	for (ll i = 0; i < n; i++)
		cin >> vec[i].first >> vec[i].second;
	sort(vec.begin(), vec.end());
	
	ll ans, sum;
	ans = sum = 0;

	for (ll i  =0 ; i < n; i++){
		saf.push_back(vec[i]);
		sum += vec[i].second;
		while (saf.size() && saf.back().first - saf.front().first >= d){
			sum -= saf.front().second;
			saf.pop_front();
		}
		ans = max(ans, sum);
	}
	cout << ans << endl;
	return 0;
}