#include<cstring>
#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	string st;
	cin >> st;
	int k(-1);
	for(int i(0); i < (int)st.size(); i++) {
		if(st[i] != 'a') {
			k = i;
			break;
		}
	}
	if(k == -1) {
		st[(int)st.size() - 1] = 'z';
	}else {
		for(int i(k); i < (int)st.size() && st[i] != 'a'; i++) {
			st[i]--;
		}
	}
	cout << st << endl;
}