#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second

const int MAXN = 100 + 3;

int n, x[MAXN], y[MAXN];
set<pair<int, int>>	st;

void go(int z){
	memcpy(y, x, sizeof(x));
	int sm = 0;
	for (int i = 0; i < n; i++)
		if (y[i] ^ z)	st.insert({y[i] - z, i}), sm += y[i] - z;
	string s;
	for (int i = 0; i < n; i++)	s += '0';
	cout << sm/2 << "\n";
	while (sm){
		if (sm == 3)	break;
		auto a = *st.rbegin();	st.erase(*st.rbegin());
		auto b = *st.rbegin();	st.erase(*st.rbegin());
	//	auto c = *st.rbegin();	st.erase(st.rbegin());
		for (int i = 0; i < n; i++)	s[i] = '0';
		s[a.S] = s[b.S] = '1';
		cout << s << "\n";
		if (a.F - 1)
			st.insert({a.F - 1, a.S});
		if (b.F - 1)
			st.insert({b.F - 1, b.S});
		sm -= 2;
	}
	if (sm){
		auto a = *st.rbegin();	st.erase(*st.rbegin());
		auto b = *st.rbegin();	st.erase(*st.rbegin());
		auto c = *st.rbegin();	st.erase(*st.rbegin());
		for (int i = 0; i < n; i++)	s[i] = '0';
		s[a.S] = s[b.S] = s[c.S] = '1';
		cout << s << "\n";
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> x[i];
	for (int i = *min_element(x, x + n); i; i--){
		int mx = 0, sm = 0;
		for (int j = 0; j < n; j++)
			sm += max(0, x[j] - i), mx = max(mx, x[j] - i);
		if (mx + mx > sm)	continue;
		cout << i << "\n";
		go(i);
		return 0;
	}
	cout << "0\n";
	int sm = 0;
	for (int i = 0; i < n; i++)	sm += x[i];
	cout << sm << "\n";
	for (int i = 0; i < n; i++)
		while (x[i]--){
			string s;
			for (int j = 0; j < n; j++)	s += '0';
			s[i] = '1';
			for (int j = 0; j < n; j++)
				if (s[j] == '0'){
					s[j] = '1';
					break;
				}
			cout << s << "\n";
		}
	return 0;
}