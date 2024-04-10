#include <bits/stdc++.h>
using namespace std;

int del[50];
set<string> S;

int main() {
	int n;
	cin>>n;
	for(int i = 1; i <= n; i++) {
		string s;
		cin>>s;
		int len = s.length();
		bool active = false;
		int start = 0;
		memset(del, 0, sizeof(del));
		for(int i = 0; i < len; i++) {
			if(s[i] == 'k') {
				if(!active) {
					active = true;
					start = i;
				}
			} else if(s[i] == 'h') {
				if(active) {
					for(int j = start; j < i; j++) {
						del[j] = 1;
					}
				}
			}

			if(s[i] != 'k') {
				active = false;
			}
		}
		string p (50, '*');
		int cntr = 0;
		for(int i = 0; i < len; i++){
			if(del[i] == 1)	continue;
			if(s[i] == 'u') {
				p[cntr] = 'o';
				p[++cntr] = 'o';
			} else {
				p[cntr] = s[i];
			}
			cntr++;
		};
		S.insert(p);
	}
	cout<<S.size()<<endl;
}