#include <cstdio>
#include <set>
using namespace std;
#define EFOUR 10000
int target, toPrint;


set<int> makeResults(int n, int depth) {
	set<int> padResults;
	if (depth <= 0) {
		padResults.clear();
		return padResults;
	}

	set<int> padRcopy = makeResults(n / 10, depth - 1);

	set<int> padRcopy2 = makeResults(n / 100, depth - 2);

	padResults.insert(n);
	padResults.insert(-n);
	for (set<int>::iterator it = padRcopy.begin();
			it != padRcopy.end();
			it++) {
		int d = n % 10;
		padResults.insert(*it - d);
		padResults.insert(*it + d);
		padResults.insert(*it * d);
	}
	for (set<int>::iterator it = padRcopy2.begin();
			it != padRcopy2.end();
			it++) {
		int d = n % 100;
		padResults.insert(*it - d);
		padResults.insert(*it + d);
		padResults.insert(*it * d);
	}
	return padResults;
}
void maybePrint(int pad, int fix) {
	if (toPrint > 0 && 0 <= fix && fix <= 9999) {
		printf("%08d\n", fix * EFOUR + pad);
		toPrint--;
	}
}

void printTickets() {
	for (int pad = 0; pad < EFOUR; pad++) {
		set<int> padResults = makeResults(pad, 4);
		for (set<int>::iterator it = padResults.begin();
				it != padResults.end();
				it++) {
			maybePrint(pad, *it + target);
			if (toPrint == 0) return;
		}
	}
	if (toPrint > 0) printf("QQ failure");
}

int main() {
	scanf("%d %d", &target, &toPrint);
	printTickets();
}