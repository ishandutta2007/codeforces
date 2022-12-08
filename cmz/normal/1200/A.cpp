#include<bits/stdc++.h>
using namespace std;
int a[20];
int aaaa;
char s[100000];
const int maxn=10;
int main() {
	int n;
	cin >> n;
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++) {
		if (s[i]=='L') {
			for (int j = 1;j <=maxn;++j) {
				if (!a[j]) {
					a[j]=1;
					break;
				}
			}
		} else if (s[i] == 'R') {
			for (int j =maxn; j >= 1; --j) {
				if (!a[j]) {
					a[j] =1;
					break;
				}
			}
		} else a[s[i]-'0'+1]=0;
	}
	for (int i = 1; i <= 10; i++) 
	if (a[i]) printf("1"); else printf("0");
	puts("");
	return 0;
}