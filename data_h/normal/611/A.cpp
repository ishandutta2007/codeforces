#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;

int a;
string of, type;

int main() {
	cin >> a >> of >> type;
	int answer = 0;
	if (type == "week") {
		for (int i = 1; i <= 366; i++) {
			if ((i + 3) % 7 + 1 == a) {
				answer++;
			}
		}
	} else if (type == "month") {
		for (int i = 1; i <= 12; i++) {
			if (i == 2) {
				answer += (a <= 29);
			} else if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) {
				answer += (a <= 31);
			} else {
				answer += (a <= 30);
			}
		}
	}
	printf("%d\n", answer);
	return 0;
}