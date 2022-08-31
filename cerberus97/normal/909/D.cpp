/*
Cerberus97
Hanit Banga
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e6 + 10;

string s;
set<pii> st, sz;

void delete_elem(pii elem);
void insert_elem(pii elem);

int main()
{
	fast_cin();
	cin >> s;
	s += 'A';
	int n = s.size();
	int l = 0;
	for (int i = 1; i < n; ++i) {
		if (s[i] != s[i - 1]) {
			st.insert({l, i - l});
			sz.insert({i - l, l});
			l = i;
		}
	}

	int del_size = 0, ans = 0;
	while (sz.size() > 1) {
		del_size += 2;
		++ans;
		auto temp = *st.begin();
		delete_elem(temp);
		++temp.second;
		insert_elem(temp);
		
		temp = *st.rbegin();
		delete_elem(temp);
		++temp.second;
		insert_elem(temp);


		vector <pii> v;
		while(!sz.empty() and sz.begin()->first <= del_size) {
			pii p = {sz.begin()->second, sz.begin()->first};
			v.pb(p);
			delete_elem(p);
		}

		sort(v.begin(), v.end());
		for (auto &i : v) {
			auto it = st.lower_bound(i);
			if (it != st.end() and it != st.begin()) {
				auto x = *it;
				--it;
				if (s[x.first] == s[it -> first]) {
					pii new_elem = {x.first, it -> second + x.second - del_size};
					delete_elem(*it);
					delete_elem(x);
					insert_elem(new_elem);
				}
			}
		}
	}

	cout << ans << endl;
}

void delete_elem(pii elem) {
	st.erase(elem);
	swap(elem.first, elem.second);
	sz.erase(elem);
}

void insert_elem(pii elem) {
	st.insert(elem);
	swap(elem.first, elem.second);
	sz.insert(elem);
}