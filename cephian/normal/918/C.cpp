#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
int l[N],h[N];

char s[N];

int main() {
	scanf("%s",s);
	int n = strlen(s), ans = 0;
	for(int i = 0; i < n; ++i) {
		if(s[i] == ')') continue;
		l[i] = h[i] = 1;
		for(int j = i+1; j < n; ++j) {
			if(s[j] == ')') {
				l[j] = l[j-1]-1;
				h[j] = h[j-1]-1;
			} else if(s[j] == '('){
				l[j] = l[j-1]+1;
				h[j] = h[j-1]+1;
			} else {
				l[j] = l[j-1]-1;
				h[j] = h[j-1]+1;
			}
			if(h[j] < 0) break;
			while(l[j] < 0) l[j] += 2;
			if(l[j] == 0) ++ans;
		}
	}
	printf("%d\n",ans);
}