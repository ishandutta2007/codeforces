#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

#define fori(i,s,e) for(int i = s; i < ((int)e); i++)
#define allof(s) (s).begin(), (s).end()

template <class T> void minify(T & a, const T & b) { if (a > b) a = b; }
template <class T> void maxify(T & a, const T & b) { if (a < b) a = b; }

char s[100008];
int n;

vector<int> stack;

int main() {
	cin >> s;
	n = strlen(s);

	fori (i, 0, n) {
		if (stack.size() && s[stack.back()] == '1' && s[i] == '0') {
			stack.pop_back();
		} else {
			stack.push_back(i);
		}
	}

	for (int x : stack) {
		s[x] = '0';
	}

	cout << s << "\n";
}