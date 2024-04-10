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

const ll MAXN = 3e5 + 20;

ll n, m;
vector<ll>	adj[MAXN], sadj[MAXN];
ll d[MAXN];

int main(){
	read_fast;
	cin >> n >> m;
	while (m--){
		ll a, b;	cin >> a >> b;	a--, b--;
		if (a > b)	swap(a, b);
		adj[a].push_back(b);
		sadj[b].push_back(a);
	}
	for (ll i = 0; i < n; i++)
		if (sadj[i].empty())	d[i] = 1;
		else{
			d[i] = 1;
			for (ll u:sadj[i])
				d[i] = max(d[i], d[u] + 1);
		}	
		
	ll ans = 0;
	for (ll i = 0; i < n; i++)
		ans = max(ans, (ll)d[i] * ll((ll)adj[i].size() + (ll)sadj[i].size()));
	cout << ans << endl;
    return 0;
}