#include <iostream>
#include <stack>

using namespace std;

bool isOpen(char ch) {
	return (
		ch == '(' ||
		ch == '[' ||
		ch == '<' ||
		ch == '{'
	);
}

bool isSameType(char ch1, char ch2) {
	return isOpen(ch1) == isOpen(ch2);
}

bool isSameKind(char ch1, char ch2) {
	if (ch1 == ch2) return true;

	if (ch1 > ch2) {
		char c = ch1;
		ch1 = ch2;
		ch2 = c;
	}

	return (
		(ch1 == '<' && ch2 == '>') ||
		(ch1 == '(' && ch2 == ')') ||
		(ch1 == '[' && ch2 == ']') ||
		(ch1 == '{' && ch2 == '}')
	);
}

int main (void) {
	ios_base::sync_with_stdio(0);
	cin >> ws;

	char ch;
	stack <char> chStk;
	long long int result = 0;

	while (cin >> ch) {
		//cout << ch;
		if (isOpen(ch)) {
			chStk.push(ch);
			continue;
		}

		if (chStk.empty()) {  // Impossible
			chStk.push(ch);   // mark the Impossible
			break;
		}

		int lastCh = chStk.top();
		chStk.pop();
		if (!isSameKind(ch, lastCh)) {
			result ++;
		}
	}

	if (!chStk.empty()) cout << "Impossible";
	else cout << result;

	return 0;
}