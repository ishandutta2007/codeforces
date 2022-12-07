#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	bool flag(true);
	char c;
	while(c = getchar()) {
		if(c == -1) {
			break;
		}
		if(c == 'C' || c == 'M' || c == 'Y') {
			flag = false;
			break;
		}
	}
	printf("%s\n", flag ? "#Black&White" : "#Color");
}