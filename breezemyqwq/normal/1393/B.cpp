#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

int cnt[100005];
int c2, c4, c6, c8, mx;

int main() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		cnt[x]++;
		mx = max(mx, x); 
	}
	for(int i = 1; i <= mx; i++) {
		if(cnt[i] >= 8) c8++;
		else if(cnt[i] >= 6) c6++;
		else if(cnt[i] >= 4) c4++;
		else if(cnt[i] >= 2) c2++;
	}
	int q;
	cin >> q;
	while(q--) {
		char c;
		int x;
		scanf(" %c%d", &c, &x);
		if(c == '+') {
			cnt[x]++;
			if(cnt[x] == 2) c2++;
			else if(cnt[x] == 4) c2--, c4++;
			else if(cnt[x] == 6) c4--, c6++;
			else if(cnt[x] == 8) c6--, c8++;
		}
		else {
			cnt[x]--;
			if(cnt[x] == 1) c2--;
			else if(cnt[x] == 3) c2++, c4--;
			else if(cnt[x] == 5) c4++, c6--;
			else if(cnt[x] == 7) c6++, c8--;
		}
		//cout << c2 << ' ' << c4 << ' ' << c6 << ' ' << c8 << endl; 
		if(c8) puts("YES");
		else if(c6 && (c2 || c4 || c6 >= 2)) puts("YES");
		else if(c4 && (c4 >= 2 || c2 >= 2)) puts("YES");
		else puts("NO");
	}
	return 0;
}