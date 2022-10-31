#include <bits/stdc++.h>
using namespace std;

vector<string> f(string s) {
	vector<string> ret;
	int i = 0;
	while(i < s.size()) {
		string t = "";
		bool type = isalpha(s[i]);
		int j = i;
		while(j < s.size() and type == isalpha(s[j])) t += s[j++];
		i = j;
		ret.push_back(t);
	}
	return ret;
}

int main() {
	int T; scanf("%d", &T); while(T--) {
		string s;
		cin >> s;
		vector<string> t = f(s);
		if(t.size() == 2) {
			int r = 0;
			for(auto it : t[0]) r = r * 26 + it - 'A' + 1;
			int c = atoi(t[1].c_str());
			printf("R%dC%d\n", c, r);
		}
		else {
			int r = atoi(t[3].c_str());
			char rr[110] = {};
			int sz = 0;
			while(r) {
				int tmp = r % 26;
				if(tmp == 0) tmp = 26;
				rr[sz++] = (tmp - 1 + 'A');
				r = r - tmp;
				r = r / 26;
			}
			while(sz--) putchar(rr[sz]);
			printf("%d\n", atoi(t[1].c_str()));
		}
	}
	return 0;
}