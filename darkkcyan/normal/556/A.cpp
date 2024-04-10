#include <iostream>
#include <stack>
using namespace std;

int main() {
	stack<char> l, r;
	int n;
	string s;
	cin >> n >> ws >> s;
	for (int i = 0; i < s.size(); ++i) l.push(s[i]);
	while (l.size()) {
		r.push(l.top());
		l.pop();
		while (l.size() and r.size() and l.top() != r.top()) l.pop(), r.pop();
	}
	cout << r.size();
	return 0;
}