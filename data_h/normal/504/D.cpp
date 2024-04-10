#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <bitset>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int N = 2e3 + 10;
const int M = 2222;
const int carry = 100000;

bitset<M> value[N], indexs[N];
char buffer[N];
int number[N];
bitset<M> cur, ind;

int main() {
	int test, counter = 0;
	scanf("%d", &test);
	while(test--) {
		cur.reset();
		scanf("%s", buffer);
		int m = strlen(buffer);

		int mm = 0;
		for(int i = m - 1; i >= 0; i -= 5) {
			number[mm] = 0;
			for(int j = max(i - 4, 0); j <= i; j++) {
				number[mm] = number[mm] * 10 + buffer[j] - '0';
			}
			mm++;
		}
		m = mm;
		//cout << number[mm - 1] << endl;
		mm = 0;
		while(m) {
			cur[mm++] = (number[0] & 1);
			for(int i = m - 1; i >= 0; i--) {
				if (i) {
					number[i - 1] += ((number[i] & 1) * carry);
				}
				number[i] >>= 1;
			}
			while(m && number[m - 1] == 0) {
				m--;
			}
		}
		//cout << cur << endl;

		ind.reset();
		for(int i = mm - 1; i >= 0; i--) {
			if (cur[i] && value[i][i]) {
				ind ^= indexs[i];
				cur ^= value[i];
			}
		}

		if (cur.none()) {
			printf("%d", (int)ind.count());
			for(int i = 0; i < counter; i++) {
				if (ind[i]) {
					printf(" %d", i);
				}
			}
			printf("\n");
		} else {
			int pos = 0;
			for(int i = 0; i < mm; i++) {
				if (cur[i]) {
					pos = i;
				}
			}
			ind[counter] = 1;
			value[pos] = cur;
			indexs[pos] = ind;
			printf("0\n");
		}

		counter++;
	}
	return 0;
}