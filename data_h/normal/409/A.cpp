#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

char buf[2][200];

int main() {
	gets(buf[0]);
	gets(buf[1]);
	int ans = 0;
	for(int i = 0; buf[0][i]; i += 2) {
		if (buf[0][i] == buf[1][i])
			continue;
		if (buf[0][i] == '8' && buf[1][i] == '[' || buf[0][i] == '(' && buf[1][i] == '8' || 
			buf[0][i] == '[' && buf[1][i] == '(')
			ans++;
		else 
			ans--;
	}
	if (ans > 0) {
		printf("TEAM 1 WINS\n");
	} else if (ans < 0) {
		printf("TEAM 2 WINS\n");
	} else {
		printf("TIE\n");
	}
	return 0;
}