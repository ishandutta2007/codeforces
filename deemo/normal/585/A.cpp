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

const ll max_n = 6e3;

ll n;
vector<ll>	ans;
bool mark[max_n];
ll d[max_n], p[max_n], v[max_n];

int main(){
	read_fast;
	cin >> n;
	for (ll i = 0; i < n; i++)
		cin >> v[i] >> d[i] >> p[i];
	for (ll i = 0; i < n; i++){
		if (mark[i])	continue;
		ans.pb(i);
		
		ll sum = 0, t = 0;
		for (ll j = i + 1; j < n; j++){
			if (mark[j])	continue;
			t++;
			p[j] -= sum + max(ll(0), v[i] - t + 1);
			if (p[j] < 0){
				mark[j] = 1;
				sum += d[j];
			}
		}
	}
	cout << ans.size() << endl;
	for (ll i = 0; i < ans.size(); i++)
		cout << ans[i] + 1 << " ";
	cout << endl;
    return 0;
}