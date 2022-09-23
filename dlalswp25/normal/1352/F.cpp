#include <bits/stdc++.h>

using namespace std;

vector<int> v;

void put(int x) {
	v.push_back(x);
}

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		if(!b) {
			if(a) for(int i = 1; i <= a + 1; i++) put(0);
			else for(int i = 1; i <= c + 1; i++) put(1);
		}
		else {
			if(!a) {
				for(int i = 1; i <= c + 1; i++) put(1);
				for(int i = 1; i <= b; i++) put(1 - v.back());
			}
			else if(!c) {
				for(int i = 1; i <= a + 1; i++) put(0);
				for(int i = 1; i <= b; i++) put(1 - v.back());	
			}
			else {
				for(int i = 1; i <= a + 1; i++) put(0);
				for(int i = 1; i <= c + 1; i++) put(1);
				for(int i = 1; i < b; i++) put(1 - v.back());
			}
		}
		for(int i : v) printf("%d", i); puts("");
		v.clear();
	}
	return 0;
}