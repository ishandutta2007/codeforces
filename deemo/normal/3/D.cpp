#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<utility>
#include<vector>

using namespace std;

typedef long long ll;

#define F first
#define S second

const int MAXN = 5e4 + 10;
const ll INF = 1e11;

ll ans;
pair<ll, ll>	vec[MAXN];
int n;
string s;
multiset<pair<ll, ll>>	st;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;	n = s.size();
	for (int i = 0; i < n; i++){
		if (s[i] == '?')
			cin >> vec[i].F >> vec[i].S;
		else{
			if (s[i] == ')')	vec[i].F = INF;
			else	vec[i].S = INF;
		}
		ans += vec[i].S;
		s[i] = ')';
	}
	if (n&1){
		cout << "-1\n";
		return	0;
	}

	s[0] = '(';
	ll ret = vec[0].S - vec[0].F;
	for (int i = 2; i < n; i += 2){
		st.insert({vec[i - 1].S - vec[i - 1].F, i - 1});
		st.insert({vec[i].S - vec[i].F, i});
		auto it = st.end();	it--;
		ret += it->first;
		s[it->second] = '(';
		st.erase(it);
	}
	ans -= ret;
	
	if (ans >= INF)
		cout << "-1\n";
	else{
		cout << ans << "\n";
		cout << s << "\n";
	}
	return	0;
}