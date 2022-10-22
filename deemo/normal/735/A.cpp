#include<bits/stdc++.h>

using namespace std;

int main(){
	int n, k;
	string s;
	cin >> n >> k >> s;
	int st, fn;
	for (int i = 0; i < n; i++)
		if (s[i] == 'G')	st = i;
		else if (s[i] == 'T')	fn = i;
	if (abs(st-fn)%k==0){
		while (st^fn && s[st] != '#'){
			if (st > fn)	st -= k;
			else st += k;
		}
		if (st==fn){
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}