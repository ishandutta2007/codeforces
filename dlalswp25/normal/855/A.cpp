#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int N;
vector<string> V;

int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; i++) {
		string s; cin >> s;
		bool exist = false;
		for(int j = 0; j < V.size(); j++) {
			if(V[j] == s) exist = true;
		}
		if(!exist) {
			puts("NO");
			V.push_back(s);
		}
		else {
			puts("YES");
		}
	}
	return 0;
}