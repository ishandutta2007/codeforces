#include <bits/stdc++.h>

using namespace std;

#define var_dump(x) cerr<<#x<<": "<<x<<'\n'
#define arr_dump(x, n) {cerr<<#x<<"[]: ";for(int i=1; i<=n; ++i) cerr<<x[i]<<" ";cerr<<'\n';}

char str[20000];
set<string> Set;

bool Can2[20000], Can3[20000];

void add(int a, int b) {
	string s;
	for(int i = a; i < b; ++i)
		s += str[i];
	Set.insert(s);
}

int main() {

	cin >> str + 1;
	int n = strlen(str + 1);

	Can2[n + 1] = Can3[n + 1] = 1;
	for(int i = n; i >= 6; --i) {
		if(Can3[i + 2]) {
			Can2[i] = 1;
			add(i, i + 2);
		} else if(Can2[i + 2]) {
			if(str[i] == str[i + 2] && str[i + 1] == str[i + 3])
				continue;
			Can2[i] = 1;
			add(i, i + 2);
		}

		if(Can2[i + 3]) {
			Can3[i] = 1;
			add(i, i + 3);
		} else if(Can3[i + 3]) {
			if(str[i] == str[i + 3] && str[i + 1] == str[i + 4] && str[i + 2] == str[i + 5])
				continue;
			Can3[i] = 1;
			add(i, i + 3);
		}
	}

	cout << Set.size() << '\n';
	for(auto x : Set)
		cout << x << '\n';
	return 0;
}