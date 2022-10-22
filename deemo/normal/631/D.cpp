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

const ll MAXN = 7e5 + 30;

ll n, m, f[MAXN];
vector<pair<ll, char>>	vec, sec;
bool mtc[MAXN];

vector<pair<ll, char>>	cook(vector<pair<ll, char>>	in){
	vector<pair<ll, char>>	ret;
	for (ll i = 0; i < (ll)in.size();){
		ll j = i, sz = 0;
		while (j < (ll)in.size() && in[i].second == in[j].second)	sz += in[j++].first;
		ret.push_back({sz, in[i].second});
		i = j;
	}
	return	ret;
}

void find_your_partner(){
	ll k = 0, sz = (ll)sec.size() - 2;
	for (ll i = 1; i < sz; i++){
		while (k && (sec[i + 1].first != sec[k + 1].first || sec[i + 1].second != sec[k + 1].second))	k = f[k];
		if (sec[k + 1].first == sec[i + 1].first && sec[i + 1].second == sec[k +1 ].second)	k++;
		f[i + 1] = k;
	}
	k = 0;
	for (ll i = 0; i < (ll)vec.size(); i++){
		while (k && (vec[i].first != sec[k + 1].first || vec[i].second != sec[k + 1].second))	k = f[k];
		if (sec[k + 1].first == vec[i].first && vec[i].second == sec[k + 1].second)	k++;
		if (k == sz){
			mtc[i] = 1;
			k = f[k];
		}
	}
}

int main(){
	read_fast;
	cin >> n >> m;
	vec.resize(n);	sec.resize(m);
	char wasted;
	for (ll i = 0; i < n; i++)	cin >> vec[i].first >> wasted >> vec[i].second;
	for (ll i = 0; i < m; i++)	cin >> sec[i].first >> wasted >> sec[i].second;
	vec = cook(vec);
	sec = cook(sec);
	
	m = sec.size();
	n = vec.size();
	if ((ll)sec.size() > 2)
		find_your_partner();//so you could play chess together

	ll ans = 0;
	for (ll i = 0; i <= (ll)vec.size() - (ll)sec.size(); i++){
		if (sec.size() == 1){
			if (sec[0].second == vec[i].second && vec[i].first >= sec[0].first)
				ans += vec[i].first - sec[0].first + 1;
		}
		else if (sec.size() == 2){
			if (i < (ll)vec.size() - 1 && vec[i].second == sec[0].second && vec[i + 1].second == sec[1].second && vec[i].first >= sec[0].first && vec[i + 1].first >= sec[1].first)
				ans++;
		}
		else if (sec[0].second == vec[i].second && vec[i].first >= sec[0].first)
			if (mtc[i + (ll)sec.size() - 2] && vec[i + (ll)sec.size() - 1].second == sec[m - 1].second && vec[i + (ll)sec.size() - 1].first >= sec[m - 1].first)	ans++;
	}
	cout << ans << "\n";
    return 0;
}