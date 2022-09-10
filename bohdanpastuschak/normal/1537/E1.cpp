#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, k; cin >> n >> k;
	string s; cin >> s;
	while((int)s.size() < k) s += s;
	string best = s;
	
	for(int i = 1; i < (int)s.size(); ++i){
		string res = s.substr(0, i);
		while((int)res.size() < k) res += res;
		best = min(best, res);
	}
	
	
	cout << best.substr(0, k) << endl;
	return 0;
}