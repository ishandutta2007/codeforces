#include <bits/stdc++.h>
 
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define cin_desync()                      \
	do {                                  \
		ios_base::sync_with_stdio(false); \
		cin.tie(0);                       \
	} while (0)                           \

#ifndef ONLINE_JUDGE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');
	cerr.write(names, comma - names) << " : " << arg1 << " | ";
	__f(comma + 1, args...);
}

#else
#define trace(...)
#endif // ifndef ONLINE_JUDGE

string get(int i, int j) {
	char ch = char(i - 1 + 'a');
	string s = "";
	s += ch;
	s += to_string(j);
	return s;
}
int n;

pii get_next(int i, int j) {
	if(n == 51 and i == 8 and j == 6) {
		return {1, 6};
	}
	if(j == 8) {
		return {i + 1, j};
	}
	if(i == 1 and j == 2) {
		return {1, 8};
	}
	if(i == 8 and j == 7) {
		return {1, 7};
	}
	if(i % 2 == 0) {
		if(j == 7) {
			return {i + 1, j};
		}
		j++;
		return {i, j};
	} else {
		if(j == 1) {
			return {i + 1, j};
		}
		j--;
		return {i, j};
	}
}

int main() {
	cin >> n;
	int i = 1, j = 1;
	cout << "a1 ";
	for(int ct = 0; ct < n - 2; ct++) {
		tie(i, j) = get_next(i, j);
		cout << get(i, j) << ' ';
	}
	if(j == 8) {
		i++;
	} else {
		if(i == 8) {
			j++;
		} else {
			j = 8;
		}
	}
	cout << get(i, j) << " h8" << endl;
}