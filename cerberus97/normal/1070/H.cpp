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

int n;
int q;

int main()
{
	cin_desync();
	cin >> n;
	map <string, string> mp;
	map <string, int> ct;
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		map <string, int> tmp;
		for(int j = 0; j < s.size(); j++) {
			for(int k = j; k < s.size(); k++) {
				if(tmp[s.substr(j, k - j + 1)]) {
					continue;
				}
				mp[s.substr(j, k - j + 1)] = s;
				ct[s.substr(j, k - j + 1)] ++;
				tmp[s.substr(j, k - j + 1)] = 1;
			}
		}
	}
	cin >> q;
	while(q--) {
		string s;
		cin >> s;
		if(ct[s]) {
			cout << ct[s] << ' ' << mp[s] << '\n';
		} else {
			cout << "0 -" << '\n';
		}
	}
}