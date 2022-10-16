#include <iostream>
#include <algorithm>

using namespace std;

pair<int, string> a[105];

bool issub(string s, string m) {
	for(int i=0;i<m.size()-s.size()+1;i++) {
		if(m.substr(i, s.size()) == s)
			return true;
	}
	return false;
}

bool ok(int n) {
	for(int i=1;i<n;i++) {
		if(!issub(a[i-1].second, a[i].second)) {
			return false;
		}
	}
	return true;
}

int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++) {
		string s;
		cin >> s;
		a[i] = {s.size(), s};
	}
	sort(a, a+n);
	if(ok(n)) {
		cout << "YES" << endl;
		for(int i=0;i<n;i++)
			cout << a[i].second << endl;
	} else {
		cout << "NO" << endl;
	}
}