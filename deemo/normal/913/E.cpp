#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int INF = 1e9;
const int XX = 1e5;

pair<int, string> d[1<<8][4];
set<pair<int, pii>> st;
pair<int, int> q[XX];

int sToMask(string s){
	int mask = 0;
	for (int i = 0; i < 8; i++)
		if (s[i] == '1')
			mask |= 1<<(7-i);
	return mask;
}

int nt(int mask){
	int res = 0;
	for (int i = 0; i < 8; i++)
		if (!(mask>>i&1))
			res |= 1<<i;
	return res;
}

int nd(int a, int b){
	int res = 0;
	for (int i = 0; i < 8; i++){
		int x = (a>>i&1) & (b>>i&1);
		res |= x<<i;
	}
	return res;
}

int rr(int a, int b){
	int res = 0;
	for (int i = 0; i < 8; i++){
		int x = (a>>i&1) | (b>>i&1);
		res |= x<<i;
	}
	return res;
}

void upd(pii state, string val){
	if (d[state.F][state.S] > make_pair((int)val.size(), val)) {
		if (d[state.F][state.S].F > val.size()) {
			st.erase({d[state.F][state.S].F, state});
			st.insert({(int)val.size(), state});
		}
		d[state.F][state.S] = make_pair(val.size(), val);
	}
}

void f(pii u, pair<int, pii> v) {
	string tt = d[u.F][u.S].S;
	string t = d[v.S.F][v.S.S].S;

	//|
	if (u.S > 0)
		upd({rr(v.S.F, u.F), 0}, t + "|" + tt);
	else
		upd({rr(v.S.F, u.F), 0}, t + "|(" + tt + ")");

	//&
	if (v.S.S > 0 && u.S > 1)
		upd({nd(v.S.F, u.F), 1}, t + "&" + tt);
	else if (v.S.S > 0)
		upd({nd(v.S.F, u.F), 1}, t + "&(" + tt + ")");
	else if (u.S > 1)
		upd({nd(v.S.F, u.F), 1}, "(" + t + ")&" + tt);
	else
		upd({nd(v.S.F, u.F), 1}, "(" + t + ")&(" + tt + ")");

}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < 1<<8; i++)
		for (int j = 0; j < 4; j++)
			d[i][j] = {INF, ""};

	d[sToMask("00001111")][3] = {1, "x"};
	st.insert({1, {sToMask("00001111"), 3}});

	d[sToMask("00110011")][3] = {1, "y"};
	st.insert({1, {sToMask("00110011"), 3}});

	d[sToMask("01010101")][3] = {1, "z"};
	st.insert({1, {sToMask("01010101"), 3}});

	int sz = 0;
	while (st.size()){
		auto v = *st.begin();
		st.erase(st.begin());
		string t = d[v.S.F][v.S.S].S;

		for (int i = 0; i < sz; i++){
			auto u = q[i];
			f(u, v);
			f(v.S, {d[u.F][u.S].F, u});
		}

		if (v.S.S == 3)
			upd({nt(v.S.F), 2}, "!" + t);
		else
			upd({nt(v.S.F), 2}, "!(" + t + ")");

		q[sz++] = v.S;
	}


	int te;
	cin >> te;
	while (te--){
		string s;	cin >> s;
		int mask = sToMask(s);;

		pair<int, string> ans(1e9, "");
		for (int i = 0; i < 4; i++)
			ans = min(ans, d[mask][i]);
		cout << ans.S << "\n";
	}
	return 0;
}