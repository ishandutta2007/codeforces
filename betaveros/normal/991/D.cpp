#include <iostream>
#include <cstring>
using namespace std;

#define fori(i,s,e) for(int i = s; i < ((int)e); i++)

char a[2][108];
int n;

int spaces[108];

int main() {
	cin >> a[0] >> a[1];
	n = strlen(a[0]);

	fori (i, 0, n) {
		spaces[i] = (a[0][i] == '0') + (a[1][i] == '0');
	}

	int answer = 0;

	fori (i, 0, n) {
		if (spaces[i] + spaces[i+1] >= 3) {
			spaces[i+1] = (spaces[i+1] + spaces[i]) - 3;
			spaces[i] = 0;
			answer++;
		}
	}

	cout << answer << "\n";
}