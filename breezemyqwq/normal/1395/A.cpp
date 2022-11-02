#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

int r, g, b, w, cnt;

int main() {
	int t;
	cin >> t;
	while(t--) {
		cnt = 0;
		scanf("%d%d%d%d", &r, &g, &b, &w);
		if(r % 2 == 0) cnt++;
		if(g % 2 == 0) cnt++;
		if(b % 2 == 0) cnt++;
		if(w % 2 == 0) cnt++;
		if(cnt >= 3) puts("Yes");
		else if(!r || !g || !b) puts("No");
		else {
			if(cnt == 2) puts("No");
			else puts("Yes");
		}
	}
	return 0;
}