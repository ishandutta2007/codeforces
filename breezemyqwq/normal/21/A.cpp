#include <bits/stdc++.h>

using namespace std;

bool check(char c) {
	if(('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z') || ('0' <= c && c <= '9') || c == '_') return true;
	return false;	
}

void Ni() {
	puts("NO");	
	exit(0);
}

int main() {
	string s;
	cin >> s;
	int i = 0;
	int cnt = 0;
	while(i < s.size() && s[i] != '@') {
		cnt++; 
		if(cnt > 16) Ni();
		if(!check(s[i])) Ni();
		i++;
	}
	if(cnt < 1) Ni();
	cnt = 0, i++;bool flag = false;
	while(i < s.size() && s[i] != '/') {
		if(s[i] == '.') {
			if(s[i - 1] == '.') Ni();
			if(cnt < 1 || cnt > 16) Ni();
			flag = true;
			cnt = 0;
			i++;
			continue;
		}
		cnt++;
		if(cnt > 32) Ni();
		if(!check(s[i])) Ni();
		i++;
	}
	if(flag) if(cnt > 16) Ni(); 
	if(cnt < 1) Ni();
	cnt = 0, i++;
	if(i == s.size() && s[i - 1] == '/') Ni(); 
	while(i < s.size()) {
		flag = true;
		cnt++;
		if(cnt > 16) Ni();
		if(!check(s[i]) && s[i] != '/') Ni();
		i++;
	}
	puts("YES");
	return 0;
}