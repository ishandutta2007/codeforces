/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

bool is_num(char c){
	if (c <= '9' && c >= '0')
		return true;
	return false;
}

string inttos(int n){
	int x = n;
	string t;
	while (x){
		t += ('A' + (x - 1) % 26);
		x = (x - 1) / 26;
	}
	reverse (t.begin(), t.end());
	return t;
}

int strtoi(string s){
	int x = 0;
	for (int i = 0; i < s.size(); i++){
		x *= 26;
		x += (s[i] - 'A' + 1);
	}
	return x;
}

int32_t main(){
	int t;
	cin >> t;
	while (t--){
		string s;
		cin >> s;
		int n = s.size();
		bool f = false;
		int c = -1, r = -1;
		for (int i = 0; i < n; i++){
			if (s[i] == 'C')
				c = i;
			else if (s[i] == 'R')
				r = i;
		}
		for (int i = 1; i < n - 1; i++){
			if (is_num(s[i - 1]) && is_num(s[i]) == false && is_num(s[i + 1]))
				f = true;
		}
//		cout << (f) << endl;
		if (f){
			string t1, t2;
			for (int i = 1; i < c; i++)
				t1 += s[i];
			for (int i = c + 1; i < n; i++)
				t2 += s[i];
			int a1 = stoi(t1), a2 = stoi(t2);
			cout << inttos(a2) << t1 << endl;
		}else{
			int num = 0;
			for (int i = 0; i < n; i++){
				if (is_num(s[i])){
					num = i;
					break;
				}
			}
			string t1, t2;
			for (int i = num; i < n; i++){
				t2 += s[i];
			}
			for (int i = 0; i < num; i++){
				t1 += s[i];
			}
			cout << "R" << t2 << "C" << strtoi(t1) << endl;
		}
	}
}