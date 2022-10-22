#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;

set<int> s, t;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;	cin >> n;
	for (int i = 0; i < n; i++){
		char c;	cin >> c;
		if (c == 'D')
			s.insert(i);
		else
			t.insert(i);
	}
	int cur = 0;
	while ((int)s.size() && (int)t.size()){
		auto it1 = s.lower_bound(cur);
		int a;
		if (it1 != s.end())	a = *it1;
		else a = *s.begin()+n;

		auto it2 = t.lower_bound(cur);
		int b;
		if (it2 != t.end()) b = *it2;
		else b = *t.begin()+n;

		if (a < b){
			a %= n;
			b %= n;
			t.erase(b);
			cur = a+1;
		}
		else{
			a %= n;
			b %= n;
			s.erase(a);
			cur = b+1;
		}
	}
	if (s.size())
		cout << "D\n";
	else
		cout << "R\n";
	return 0;
}