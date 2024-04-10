#include <bits/stdc++.h>
using namespace std;
const int MN = 1e6+5;
char s[MN]; int cnt[3]; int sofar[3];
int main() {
	int n;
	scanf ("%d",&n);
	scanf ("%s",s+1);
	for (int i = 1; i <= n; i++) cnt[s[i]-'0']++;
	int need = n/3;
	for (int i = 1; i <= n; i++) {
		int cur = s[i]-'0';
		if (cnt[cur] > need) {
			for (int j = 0; j < 3; j++) if ((j < cur || sofar[cur] == need) && cnt[j] < need) {
				s[i] = j+'0';
				--cnt[cur];
				++cnt[j];
				break;
			}
		}
		++sofar[s[i]-'0'];
	}
	printf ("%s\n",s+1);
    return 0;
}